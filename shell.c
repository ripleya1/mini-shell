// https://canvas.xavier.edu/courses/84094/assignments/1039002

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "shell.h"

int main(){
    char *inputStr;
    inputStr = malloc(200 * sizeof(char));
    
    char ***tokenVect;
    tokenVect = malloc(sizeof(char**) * 200 * 200);
    
    int c = 0;
    int cont = TRUE;
    char *whitespace = " \t\f\r\v\n";
    
    while(cont){
        cont = FALSE;
        printf("%s", "> ");
        inputStr = fgets(inputStr, 200 * sizeof(char), stdin); // get user input
        if(inputStr == NULL){
            printf("%s", "Invalid input.\n");
            return 0;
        }

        // tokenize each token and put into 2d array
        char *tokenizedStr = strtok(inputStr, whitespace);
        puts(tokenizedStr);
        tokenVect[0] = tokenizedStr;
        puts(tokenVect[0]);
        while(tokenizedStr != NULL){
            tokenVect[c] = tokenizedStr;
            c = c + 1;
            tokenizedStr = strtok(NULL, whitespace);
        }
    }
    // free(inputStr);

    int i = 0;
    int j = 0;
    while(tokenVect[i] != NULL){
        puts(tokenVect[i]);
        i++;
    }
}