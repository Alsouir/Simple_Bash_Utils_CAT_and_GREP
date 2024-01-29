#include <stdio.h>
#include <string.h>

#include "options.h"

/*int checkInputCommand (char *commandCat, char *option);
void optionCatAndFileName (char *commandCat);
void deleteSpace (char *command);*/

int optionCat(char argc, char **argv, char *options);
void callingOfOptions(char argc, char **argv);

int main(int argc, char **argv) {
  // char commandCat[256];
  // fgets (commandCat, sizeof(commandCat), stdin);
  // optionCatAndFileName (commandCat);
  callingOfOptions(argc, argv);
  return 0;
}

int optionCat(char argc, char **argv, char *options) {
  int k = 0;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      int len = strlen(argv[i]);
      for (int j = 1; j < len; j++) {
        if (argv[i][j] == 'b' || argv[i][j] == 'e' || argv[i][j] == 'v' ||
            argv[i][j] == 't' || argv[i][j] == 'n' || argv[i][j] == 's' ||
            argv[i][j] == 'E' || argv[i][j] == 'T') {
          options[k] = argv[i][j];
          k++;
        } else {
          printf("cat: illegal option -- %c\n", argv[i][j]);
          printf("usage: cat [-benstuv] [file ...]");
          k = -1;
          break;
        }
      }
    }
  }
  return k;
}

void callingOfOptions(char argc, char **argv) {
  char options[10] = "\0";
  int k = optionCat(argc, argv, options);
  if (k != -1) {
    for (int i = 1 + k; i < argc; i++) {
      readLine(argv[i], options);
    }
  }
}
/*void callingOfOptions (char argc, char **argv){
    char options[10] = "\0";
    optionCat (argc, argv, options);
    int len = strlen(options);
    if (options[0] != '0') {
        for (int i = 0; i < len; i++) {
            if (options[0] != 'v' && i < 1){
                switch (options[i])
                {
                    case 'b':
                        optionB (argv[argc - 1]);
                        break;
                    case 'e':
                        optionE (argv[argc - 1], options[i]);
                        break;
                    case 'E':
                        optionE (argv[argc - 1], options[i]);
                        break;
                    case 'n':
                        optionN (argv[argc - 1]);
                        break;
                    case 's':
                        optionS (argv[argc - 1]);
                        break;
                    case 't':
                        optionT (argv[argc - 1], options[i]);
                        break;
                    case 'T':
                        optionT (argv[argc - 1], options[i]);
                        break;
                    default:
                        break;
                }
            } else if (options[0] == 'v' && i < 2) {
                switch (options[i])
                {
                    case 'e':
                        optionE (argv[argc - 1], options[i]);
                        break;
                    case 't':
                        optionT (argv[argc - 1], options[i]);
                        break;
                    default:
                        break;
                }
            }

        }
    }
}





void deleteSpace (char *command){
    char doubleCommand[256];
    while (command[0] == ' ') {
        int len = strlen (command);
        strcpy(doubleCommand, command);
        for (int j = 0; j < len - 1; j++) {
            command[j] = doubleCommand [j+1];
        }
        command[len - 1] = '\0';
    }
}

int checkInputCommand (char *commandCat, char *option) {
    int flag;

    if (commandCat[0] == 'c' && commandCat[1] == 'a' && commandCat[2] == 't') {
        int len = strlen (commandCat);
        for (int i = 0; i < len - 3; i++){
            commandCat[i] = commandCat[i+3];
        }
        commandCat[len - 3] = '\0';

        if (commandCat[0] == '-' ){
            flag = 1;
            int len = strlen (commandCat);
            if (commandCat [1] != 'v') {
                *option = commandCat [1];
            }
            for (int i = 0; i < len - 2; i++){
                commandCat[i] = commandCat[i+2];
            }
            commandCat[len - 2] = '\0';

            if (commandCat[0] == '-' &&  commandCat[1] == 'v') {
                if (commandCat [1] != 'v') {
                    *option = commandCat [1];
                }
                flag = 2;
                int len = strlen (commandCat);
                for (int i = 0; i < len - 2; i++){
                    commandCat[i] = commandCat[i+2];
                }
                commandCat[len - 2] = '\0';

            }
        } else {
            printf("command entered incorrectly");
            flag = 0;
        }
        //printf ("%s", commandCat);
    } else {
        printf ("this is not a cat command");
        flag = 0;
    }
    return flag;
}

void optionCatAndFileName (char *commandCat) {

    char option;
    int resultCheckInputCommand = checkInputCommand (commandCat, &option);
    if (resultCheckInputCommand == 0) {
        return;
    }
    int i = 0;
    int len = strlen(commandCat);
    while (i < len){
        if (commandCat[i] == '\n' || commandCat[i] == ' '){
            commandCat[i] = '\0';
        }
        i++;
    }
    //printf ("1%s123344", commandCat);

    switch (option)
    {
    case 'b':
        optionB (commandCat);
        break;
    case 'e':
        optionE (commandCat);
        optionV (commandCat);
        break;
    case 'E':
        optionE (commandCat);
        break;
    case 'n':
        optionN (commandCat);
        break;
    case 's':
        optionS (commandCat);
        break;
    case 't':
        optionT (commandCat);
        optionV (commandCat);
        break;
    case 'T':
        optionT (commandCat);
        break;
    default:
        printf ("there is no such option");
        break;
    }
}*/