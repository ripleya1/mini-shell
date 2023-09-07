// https://canvas.xavier.edu/courses/84094/assignments/1039002

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "shell.h"

int main(){
    char *inputStr;
    inputStr = malloc(200 * sizeof(char));
    int *numTokens;
    char ***tokenVect;
    tokenVect = malloc(sizeof(char**) * 200 * 200);
    int c = 0;
    int cont = TRUE;
    char *whitespace = " \t\f\r\v\n";
    while(cont){
        cont = FALSE;
        printf("%s", "> ");
        inputStr = fgets(inputStr, 200 * sizeof(char), stdin); // get user input
        char *tokenizedStr = strtok(inputStr, whitespace);
        // tokenize each token
        while(tokenizedStr != NULL){
            tokenVect[c] = tokenizedStr;
            c++;
            tokenizedStr = strtok(inputStr, whitespace);
        }
    }
    free(inputStr);

    int i = 0;
    int j = 0;
    while(tokenVect[i] != NULL){
        printf("%s ", tokenVect[0]);
        i++;
    }
}