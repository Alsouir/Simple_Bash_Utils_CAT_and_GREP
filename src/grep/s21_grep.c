#include "s21_grep.h"
struct Options grepFlag = {
    .e = 0, .i = 0, .v = 0, .c = 0, .l = 0, .n = 0, .h = 0, .f = 0, .o = 0};

int main(int argc, char **argv) {
  if (countFlagsGrep(argc, argv, &grepFlag) == 1) {
    char *pattern;
    if (grepFlag.f == 1) {
      FILE *patternFile = fopen(argv[optind], "r");
      if (patternFile != NULL) {
        char patternFromFile[4096];
        if (fgets(patternFromFile, sizeof(patternFromFile), patternFile) !=
            NULL) {
          patternFromFile[strcspn(patternFromFile, "\n")] = '\0';
          pattern = patternFromFile;
        }
      } else {
        fprintf(stderr, "Cannot open file: %s\n", argv[optind]);
        return 0;
      }
      fclose(patternFile);
      optind++;
    } else {
      pattern = argv[optind];
    }
    int files = 0;
    if (argc - 3 >= optind) {
      files = 1;
    }
    while (optind < argc) {
      workFlagsGrep(grepFlag, argv[optind], pattern, files);
      optind++;
    }
  }

  return 0;
}

int countFlagsGrep(int argc, char **argv, struct Options *grepFlag) {
  int flag = 1;
  int readFlag;
  int optionIndex = 0;
  const struct option arr[] = {{NULL, 0, NULL, 0}};
  while ((readFlag = getopt_long(argc, argv, "efivclnhsfo", arr,
                                 &optionIndex)) != -1) {
    switch (readFlag) {
      case 'i': {
        grepFlag->i = 1;
        break;
      };
      case 'e': {
        grepFlag->e = 1;
        grepFlag->f = 0;
        break;
      };
      case 'h': {
        grepFlag->h = 1;
        break;
      }
      case 'v': {
        grepFlag->v = 1;
        break;
      }
      case 'c': {
        grepFlag->c = 1;
        break;
      }
      case 'l': {
        grepFlag->l = 1;
        break;
      }
      case 'n': {
        grepFlag->n = 1;
        break;
      }
      case 'f': {
        grepFlag->e = 0;
        grepFlag->f = 1;
        break;
      }
      case 's': {
        opterr = 0;
        break;
      }
      case 'o': {
        grepFlag->o = 1;
        break;
      }
      default: {
        flag = 0;
        fprintf(stderr, "invalid option -- %c", readFlag);
        break;
      }
    }
  }
  return flag;
}

int workFlagsGrep(struct Options grepFlag, char *file, char *pattern,
                  int files) {
  int counter = 0;
  int counterString = 0;
  regex_t reegex;
  regcomp(&reegex, pattern, REG_EXTENDED);
  FILE *f;
  int resSearch;
  if ((f = fopen(file, "r")) != NULL) {
    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    fseek(f, 0, SEEK_SET);
    char line[size];
    while ((fgets(line, sizeof(line), f)) != NULL) {
      counterString++;

      resSearch = regexec(&reegex, line, 0, NULL, 0);
      if (grepFlag.i == 1) {
        regfree(&reegex);
        regcomp(&reegex, pattern, REG_ICASE);
        resSearch = regexec(&reegex, line, 0, NULL, 0);
      }
      if (grepFlag.v == 1) {
        resSearch = !resSearch;
      }
      if (grepFlag.h == 1 || grepFlag.f == 1) {
        files = 0;
      }
      if (resSearch == 0) {
        counter++;
        if (line[strlen(line) - 1] != '\n') {
          int end = strlen(line);
          line[end] = '\n';
          line[end + 1] = '\0';
        }
        if (grepFlag.c == 0 && grepFlag.l == 0) {
          if (files > 0 && grepFlag.n == 1) {
            printf("%s:%d:%s", file, counterString, line);
          } else if (files > 0 && grepFlag.n == 0) {
            printf("%s:%s", file, line);
          } else if (files == 0 && grepFlag.n == 1) {
            printf("%d:%s", counterString, line);
          } else if (grepFlag.o == 1) {
            char *str = line;
            while ((str = strstr(str, pattern)) != NULL) {
              printf("%s\n", pattern);
              str += strlen(pattern);
            }
          } else {
            printf("%s", line);
          }
        }
      }
    }
    if (grepFlag.c == 1 && grepFlag.l == 0) {
      if (files > 0) {
        printf("%s:%d\n", file, counter);
      } else {
        printf("%d\n", counter);
      }
    }
    if (grepFlag.c == 1 && grepFlag.l == 1) {
      if (counter != 0) {
        counter = 1;
      }
      if (files > 0) {
        printf("%s:%d\n", file, counter);
      } else {
        printf("%d\n", counter);
      }
    }
    if (grepFlag.l == 1 && counter != 0) {
      printf("%s\n", file);
    }
    fclose(f);
  }
  regfree(&reegex);
  return 1;
}
