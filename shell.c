// https://canvas.xavier.edu/courses/84094/assignments/1039002

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "shell.h"

int main(){
    char *inputStr;
    inputStr = malloc(200 * sizeof(char)); // TODO: change size
    
    getInput(inputStr);

    char ***tokenv;
    tokenv = malloc(sizeof(char**) * 200 * 200);
    int tokenc;

    tokenc = tokenize(inputStr, tokenv);

    int pid;
    pid = fork();
    // child
    if(pid == 0){
        int execErrCode;
        char *pathFromTok;
        pathFromTok = tokenv[0];
        // rewrite token array
        for(int i = 1; i < tokenc; i++){
            tokenv[i - 1] = tokenv[i];
        }
        // exec
        execErrCode = execv(pathFromTok, tokenv);
        if(execErrCode == -1){
            perror("Invalid command");
            exit(0);
        }
    }
    // parent
    else{
        wait(NULL);
    }
}

void getInput(char *inputStr){
    int cont = TRUE;
    while(cont){
        printf("%s", "> ");
        inputStr = fgets(inputStr, 200 * sizeof(char), stdin); // get user input
        // TODO: When the user types a blank line just ignore it and print another prompt.
        if(inputStr[0] == '\0'){
            cont = TRUE;
        }
        else{
            cont = FALSE;
        }
    }
}

int tokenize(char *input, char ***tokenVector){
    char *whitespace = " \t\f\r\v\n";
    int c = 0;
    
    // tokenize each token and put into 2d array
    char *tokenizedStr = strtok(input, whitespace);
    while(tokenizedStr != NULL){
        tokenVector[c] = tokenizedStr;
        c = c + 1;
        tokenizedStr = strtok(NULL, whitespace);
    }

    int i = 0;
    while(tokenVector[i] != NULL){
        // printing for debugging
        // puts(tokenVector[i]);
        i++;
    }
    return i; // returns the number of tokens
}

// void itsForkinTime(){
    
// }