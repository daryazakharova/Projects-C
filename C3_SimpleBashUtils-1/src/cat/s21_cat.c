#include "s21_cat.h"

int main(int argc, char **argv) {
  const struct option longopts[] = {{"number-nonblank", 0, NULL, 'b'},
                                    {"number", 0, NULL, 'n'},
                                    {"squeeze-blank", 0, NULL, 's'},
                                    {0, 0, 0, 0}};
  Option opt = {0};
  if (optionRead(argc, argv, longopts, &opt)) {
    for (int i = optind; i < argc; i++) {
      fileOpen(argc, argv, &opt);
    }
  }
  return 0;
}

int optionRead(int argc, char **argv, const struct option *longopts,
               Option *opt) {
  int getopt, flag = 1;
  while ((getopt = getopt_long(argc, argv, "+benstvET", longopts, NULL)) !=
         -1) {
    switch (getopt) {
      case 'b':
        opt->b = 1;
        break;
      case 'n':
        opt->n = 1;
        break;
      case 's':
        opt->s = 1;
        break;
      case 'e':
        opt->e = 1;
        opt->v = 1;
        break;
      case 't':
        opt->t = 1;
        opt->v = 1;
        break;
      case 'v':
        opt->v = 1;
        break;
      case 'E':
        opt->E = 1;
        break;
      case 'T':
        opt->T = 1;
        break;
      default:
      case '?':
        flag = 0;
        break;
    }
  }
  return flag;
}

void fileOpen(int argc, char **argv, Option *opt) {
  while (optind < argc) {
    FILE *fp;
    fp = fopen(argv[optind], "r");
    if (!fp) {
      fprintf(stderr, "21_cat: %s: No such file or directory\n", argv[optind]);
      break;
    } else {
      textEditor(fp, opt);
      optind++;
    }
    fclose(fp);
  }
}

void textEditor(FILE *fp, Option *opt) {
  int ch, prev;
  int numLine = 0;
  int lineEmpty = 0;
  for (prev = '\n'; (ch = fgetc(fp)) != EOF; prev = ch) {
    if (!(opt->s && prev == '\n' && ch == '\n' && lineEmpty)) {
      if (prev == '\n' && ch == '\n')
        lineEmpty = 1;
      else
        lineEmpty = 0;
      if (((opt->n && !opt->b) || (opt->b && ch != '\n')) && prev == '\n') {
        fprintf(stdout, "%6d\t", ++numLine);
      }
      if ((opt->E || opt->e) && ch == '\n') {
        fprintf(stdout, "$");
      }
      if ((opt->T || opt->t) && ch == '\t') {
        fprintf(stdout, "^");
        ch = 'I';
      }
      if (opt->v) {
        if (ch > 127 && ch < 160) fprintf(stdout, "M-^");
        if ((ch < 32 && ch != '\n' && ch != '\t') || ch == 127)
          fprintf(stdout, "^");
        if ((ch < 32 || (ch > 126 && ch < 160)) && ch != '\n' && ch != '\t') {
          if (ch > 126)
            ch = ch - 128 + 64;
          else
            ch = ch + 64;
        }
      }
      fputc(ch, stdout);
    }
  }
  ch = fgetc(fp);
}