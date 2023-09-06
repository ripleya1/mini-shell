// https://canvas.xavier.edu/courses/84094/assignments/1039002

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "shell.h"

int main(){
    char *inputStr;
    int *numTokens;
    char *tokenVect[200];
    int cont = TRUE;
    while(cont){
        getInput(inputStr, &numTokens, &tokenVect);
        tokenize(, );
    }
}

char *getInput(char *inputStr, int *numTokens, char *tokenVect){
    inputStr = malloc(200 * sizeof(char));
    char *whitespace = " \t\f\r\v\n";
    printf("%s", "> ");
    inputStr = fgets(inputStr, 200 * sizeof(char), stdin); // get user input

}

char* tokenize(char *input, int *token_count, char ***token_vector){
    // tokenize
    char *tokenizedStr = strtok(input, whitespace);
    while(tokenizedStr != NULL){
        printf("%s", tokenizedStr);
        tokenizedStr = strtok(NULL, whitespace); // get next token
    }
}