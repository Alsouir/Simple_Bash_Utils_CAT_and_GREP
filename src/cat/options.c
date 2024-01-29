#include "options.h"

#include <stdio.h>
#include <string.h>

FILE* openFile(char fileName[256]) {
  FILE* file;
  file = fopen(fileName, "r");
  if (file == NULL) {
    printf("Could not open the file");
    return NULL;
  }
  return file;
}

void readLine(char fileName[256], char options[10]) {
  char line[1000];
  FILE* file = openFile(fileName);
  if (file == NULL) {
    return;
  }
  int len = strlen(options);
  int flagB = 0, flage = 0, flagt = 0, flagS = 0, flagV = 0, flagE = 0,
      flagT = 0, flagN = 0;
  for (int j = 0; j < len; j++) {
    if (options[j] == 'b')
      flagB = 1;
    else if (options[j] == 'e') {
      flage = 1;
      flagV = 1;
    } else if (options[j] == 'E')
      flagE = 1;
    else if (options[j] == 'n')
      flagN = 1;
    else if (options[j] == 's')
      flagS = 1;
    else if (options[j] == 't') {
      flagt = 1;
      flagV = 1;
    } else if (options[j] == 'T')
      flagT = 1;
    else if (options[j] == 'v')
      flagV = 1;
  }
  int numberLine = 1;
  int emptyLine = 0;
  while (fgets(line, sizeof(line), file)) {
    int lenLine = strlen(line);
    for (int i = 0; i < lenLine; i++) {
      if (flagB == 1 && line[0] != '\n' && i == 0) {
        printf("%6d\t", numberLine);
        numberLine++;
      }

      if (flagS == 1 && line[0] == '\n' && emptyLine == 0) {
        emptyLine = 1;
      } else if (flagS == 1 && line[0] == '\n' && emptyLine == 1) {
        emptyLine = 2;
      } else if (flagS == 1 && line[0] != '\n' &&
                 (emptyLine == 2 || emptyLine == 1)) {
        emptyLine = 0;
      }
      if (flagN == 1 && flagB == 0 && i == 0 &&
          (emptyLine == 1 || emptyLine == 0)) {
        printf("%6d\t", numberLine);
        numberLine++;
      }
      if (((flagt == 1 && line[i] == '\t') || (flage == 1 && line[i] == '\n') ||
           (flagV == 1 && (line[i] < 32 || line[i] > 126))) &&
          (emptyLine == 1 || emptyLine == 0)) {
        if (flagt == 1 && line[i] == '\t') printf("^I");
        if (flage == 1 && line[i] == '\n') printf("$\n");
        if (line[i] == '\r') {
          printf("^M");
        } else if (line[i] == '\t' && flagt != 1) {
          printf("\t");
        } else if (line[i] == '\n' && flage != 1) {
          printf("\n");
        } else if (line[i] < 32 && line[i] != '\t' && line[i] != '\n') {
          printf("^%c", line[i] + 64);
        } else if (line[i] > 126) {
          printf("\\x%02x", line[i]);
        }
      } else if (((flagT == 1 && line[i] == '\t') ||
                  (flagE == 1 && line[i] == '\n')) &&
                 (emptyLine == 1 || emptyLine == 0)) {
        if (flagT == 1 && line[i] == '\t') printf("^I");
        if (flagE == 1 && line[i] == '\n') printf("$\n");
      } else if (emptyLine == 1 || emptyLine == 0) {
        printf("%c", line[i]);
      }
    }
  }
  fclose(file);
}

/*void optionB (char fileName[256]){
    int numberLine = 1;
    char line [1000];
    FILE* file = openFile(fileName);
    if (file == NULL){
        return;
    }
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '\n')
            printf("%s", line);
        else {
            printf("%6d\t%s", numberLine, line);
            numberLine++;
        }
    }
    fclose(file);
}

void optionE (char fileName[256], char option){
    char line [1000];
    FILE* file = openFile(fileName);
    if (file == NULL){
        return;
    }
    while (fgets(line, sizeof(line), file)) {

        int len = strlen (line);
        for (int i = 0; i < len; i++){
            if (i == len -1 && feof(file) != 1){
                printf("$\n");
            }else {
                if (option == 'e'){
                    optionV (line[i]);
                } else {
                    printf("%c", line[i]);
                }

            }
        }
    }
    fclose(file);
}

void optionN (char fileName[256]){
    int numberLine = 1;
    char line [1000];
    FILE* file = openFile(fileName);
    if (file == NULL){
        return;
    }
    while (fgets(line, sizeof(line), file)) {
        printf("%6d\t%s", numberLine, line);
        numberLine++;
    }
    fclose(file);
}

void optionS (char fileName[256]){
    int emptyLine = 1;
    char line [1000];
    FILE* file = openFile(fileName);
    if (file == NULL){
        return;
    }
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '\n'){
            if (emptyLine == 1){
                printf("%s", line);
                emptyLine = 0;
            }
        } else {
            printf("%s", line);
            emptyLine = 1;
        }
    }
    fclose(file);
}

void optionT (char fileName[256], char option){
    char line [1000];
    FILE* file = openFile(fileName);
    if (file == NULL){
        return;
    }
    while (fgets(line, sizeof(line), file)) {
        int i = 0;
        while (line[i] != '\n'){

            if (line[i] == '\t'){
                printf("^I");
            } else {
                if (option == 't'){
                    optionV (line[i]);
                } else {
                    printf("%c", line[i]);
                }
            }
            i++;
        }
        if (feof(file) != 1){
            printf("\n");
        }

    }
    fclose(file);
}

void optionV (char symbvol){

    if (symbvol != '\t' && symbvol != '\n') {
        if ( symbvol == '\r'){
            printf("^M");
        } else if (symbvol < 32) {
            printf("^%c", symbvol + 64);
        } else if (symbvol > 126){
            printf("\\x%02x", symbvol);

        } else {
            printf("%c", symbvol);
        }
    } else {
        printf("%c", symbvol);
    }



    while (fgets(line, sizeof(line), file)) {
        int i = 0;
        while (line[i] != '\n'){
            if (line[i] == '\t'){
                printf("^I");
            } else {
                printf("%c", line[i]);
            }
            i++;
        }
        printf("\n");
    }
}*/

/*void readLine (char fileName[256], char options[256]){
    int numberLine = 1;
    char line [1000];
    FILE* file = openFile(fileName);
    if (file == NULL){
        return;
    }
    while (fgets(line, sizeof(line), file)) {
        int lenLine = sizeof(line);
        int numberLine = 1;
        for (int i = 0; i < lenLine; i++){
            int len = strlen (options);
            for (int j = 0; j < len; j++){
                if (options[j] == 'b' && i == 0 && line[0] == '\n') {
                    printf("%6d", numberLine);
                    numberLine++;
                }
                if (options[j] == 'e' && i ==  && line[0] == '\n') {
                    printf("%6d", numberLine);
                    numberLine++;
                }
            }

        }

    }
    fclose(file);
}

void optionB(char fileName[256]);
void optionE(char fileName[256], char option);
void optionN(char fileName[256]);
void optionS(char fileName[256]);
void optionT(char fileName[256], char option);
void optionV(char symbvol);


*/
