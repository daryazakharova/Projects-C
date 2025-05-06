#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX 1024

typedef struct {
  int i;
  int e;
  int n;
  int s;
  int v;
  int c;
  int l;
  int h;
  int f;
  int o;
  int regexFlag;
  int countFiles;
  char strComp[N_MAX];
} grepOption;

void optionReadGrep(int argc, char *argv[], grepOption *opt);
void fileOpen(int argc, char *argv[], grepOption *opt);
void generationRE(FILE *file, grepOption *opt, char *fileName);
void optE(grepOption *opt, char *pattern);
void optF(grepOption *opt, char *fileName);