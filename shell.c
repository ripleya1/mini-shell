// https://canvas.xavier.edu/courses/84094/assignments/1039002

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "shell.h"

int main(){
    char *inputStr;
    inputStr = malloc(200 * sizeof(char)); // TODO: change size
    
    getInput(inputStr);

    char ***tokenVect;
    tokenVect = malloc(sizeof(char**) * 200 * 200);
    int tokenCount;

    tokenCount = tokenize(inputStr, tokenVect);
}

void getInput(char *inputStr){
    int cont = TRUE;
    while(cont){
        cont = FALSE;
        printf("%s", "> ");
        inputStr = fgets(inputStr, 200 * sizeof(char), stdin); // get user input
        if(inputStr == NULL){
            printf("%s", "Invalid input.");
            cont = TRUE;
        }
        printf("%s", "\n");
    }
}

int tokenize(char *input, char ***token_vector){
    char *whitespace = " \t\f\r\v\n";
    int c = 0;
    
    // tokenize each token and put into 2d array
    char *tokenizedStr = strtok(input, whitespace);
    // puts(tokenizedStr);
    token_vector[0] = tokenizedStr;
    // puts(tokenVect[0]);
    while(tokenizedStr != NULL){
        token_vector[c] = tokenizedStr;
        c = c + 1;
        tokenizedStr = strtok(NULL, whitespace);
    }
    // shit breaks weirdly if I do this
    // free(input);

    int i = 0;
    while(token_vector[i] != NULL){
        puts(token_vector[i]);
        i++;
    }
    return i; // returns the number of tokens
}