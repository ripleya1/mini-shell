// https://canvas.xavier.edu/courses/84094/assignments/1039002

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "shell.h"

// chdir when cd in first arg
// exit when exit in first arg

const int INPUTSIZE = 1000;

int main(){
    int cont = TRUE;
    while(cont){
        char *inputStr;
        inputStr = malloc(INPUTSIZE * sizeof(char));
        
        getInput(inputStr);

        char ***tokenv;
        tokenv = malloc(sizeof(char**) * INPUTSIZE * INPUTSIZE);
        int tokenc;

        tokenc = tokenize(inputStr, tokenv);

        int pid;
        pid = fork();
        // child
        if(pid == 0){
            int execErr;
            char *pathFromTok;
            pathFromTok = tokenv[0];
            // rewrite token array
            for(int i = 1; i < tokenc; i++){
                tokenv[i - 1] = tokenv[i];
            }
            // if(strcmp(pathFromTok, "exit") == 0){
            //     puts("aaa");
            //     exit(0);
            //     cont = FALSE;
            //     break;
            // }
            // else if(strcmp(pathFromTok, "cd")){
            //     int chdirErr;
            //     chdirErr = chdir();
            //     if(chdirErr != 0){
            //         perror("cd failed");
            //     }
            // }
            // else{
                // child executes command, exits if invalid
                execErr = execvp(pathFromTok, tokenv);
                if(execErr == -1){
                    perror("Invalid command");
                    exit(0);
                }
            // }
        }
        // parent
        else{
            wait(NULL); // parent waits
        }
    }
}

void getInput(char *inputStr){
    int numTokens;
    printf("%s", "> ");
    inputStr = fgets(inputStr, INPUTSIZE * sizeof(char), stdin); // get user input
    // exits on EOF (Ctrl + D)
    if(inputStr == NULL){
        exit(0);
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