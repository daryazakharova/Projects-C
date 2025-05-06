#include "s21_grep.h"

int main(int argc, char **argv) {
  if (argc > 2) {
    grepOption optGrep = {0};
    optionReadGrep(argc, argv, &optGrep);
    fileOpen(argc, argv, &optGrep);
  } else {
    fprintf(stderr, "Usage: grep [OPTION]... PATTERNS [FILE]...\n");
  }
  return 0;
}

void optionReadGrep(int argc, char *argv[], grepOption *opt) {
  int readOpt;
  while ((readOpt = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL)) !=
         -1) {
    switch (readOpt) {
      case 'e':
        optE(opt, optarg);
        opt->e = 1;
        break;
      case 'n':
        opt->n = 1;
        break;
      case 's':
        opt->s = 1;
        break;
      case 'i':
        opt->regexFlag |= REG_ICASE;
        break;
      case 'v':
        opt->v = 1;
        break;
      case 'c':
        opt->c = 1;
        break;
      case 'l':
        opt->l = 1;
        break;
      case 'h':
        opt->h = 1;
        break;
      case 'f':
        optF(opt, optarg);
        opt->f = 1;
        break;
      case 'o':
        opt->o = 1;
        break;
      default:
      case '?':
        exit(EXIT_FAILURE);
        break;
    }
  }

  if (!opt->e && !opt->f) {
    optE(opt, argv[optind]);
    optind++;
  }
  opt->countFiles = (argc - optind);
  opt->regexFlag |= REG_EXTENDED;
  opt->strComp[strlen(opt->strComp) - 1] = 0;
}

void optE(grepOption *opt, char *pattern) {
  char *c = "|\0";
  strcat(opt->strComp, pattern);
  strcat(opt->strComp, c);
}

void optF(grepOption *opt, char *fileName) {
  FILE *file = fopen(fileName, "r");
  if (file == NULL) {
    fprintf(stderr, "s21_grep: %s: No such file or directory\n", fileName);
    exit(EXIT_FAILURE);
  } else {
    char word[N_MAX];
    while (fscanf(file, "%1023s", word) == 1) {
      optE(opt, word);
    }
    fclose(file);
  }
}

void fileOpen(int argc, char *argv[], grepOption *opt) {
  for (int i = optind; i < argc; i++) {
    char *file_Name = argv[i];
    FILE *fp;
    fp = fopen(file_Name, "r");
    if (fp == NULL) {
      if (!opt->s)
        fprintf(stderr, "s21_grep: %s: No such file or directory\n", file_Name);
    } else {
      generationRE(fp, opt, file_Name);
      fclose(fp);
    }
  }
}

void generationRE(FILE *file, grepOption *opt, char *fileName) {
  regex_t re;
  char str[N_MAX];
  int numberLine = 0;
  int count = 0;
  if ((regcomp(&re, opt->strComp, opt->regexFlag)) != 0) {
    printf("Error analyzing regular expression\n");
    exit(EXIT_FAILURE);
  }
  while (fgets(str, N_MAX, file) != NULL) {
    numberLine++;
    int rx = regexec(&re, str, 0, NULL, 0);
    if (opt->v) rx = !rx;
    if (!rx) {
      count++;
      if (opt->l) {
        if (opt->c) {
          printf("%s:%d\n", fileName, count);
          printf("%s\n", fileName);
        } else
          printf("%s\n", fileName);
        break;
      }
      if (opt->c) continue;
      if (!opt->o) {
        if (opt->countFiles > 1 && !opt->h) printf("%s:", fileName);
        if (opt->n) printf("%d:", numberLine);
        printf("%s", str);
        if (str[strlen(str) - 1] != '\n') printf("\n");
      }
    }
  }
  if (opt->c && !opt->l) {
    if (opt->countFiles < 2 || opt->h)
      printf("%d\n", count);
    else
      printf("%s:%d\n", fileName, count);
  }
  regfree(&re);
}
