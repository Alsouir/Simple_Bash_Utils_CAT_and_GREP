#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

#ifndef S21_GREP_H
#define S21_GREP_H

struct Options {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
};

int main(int argc, char **argv);
int countFlagsGrep(int argc, char **argv, struct Options *grepFlag);
int workFlagsGrep(struct Options grepFlag, char *file, char *pattern,
                  int files);

#endif
