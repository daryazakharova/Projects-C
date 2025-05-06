#ifndef S21_CAT
#define S21_CAT

#include <getopt.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  int b;
  int e;
  int n;
  int s;
  int v;
  int t;
  int T;
  int E;
} Option;

void fileOpen(int argc, char **argv, Option *opt);
int optionRead(int argc, char **argv, const struct option *longopts,
               Option *opt);
void textEditor(FILE *fp, Option *opt);

#endif
