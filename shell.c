/*
Aaron Ripley
9/9/23
A mini shell. Given a command from the default PATH (usr/bin), it uses execvp to execute that command using any arguments that the user passed.
The execution of the command is forked, creating a new process, with the child process running the command and the parent process waiting for the child to complete. 
The shell repeatedly takes input from the user until it encounters an end of file character, done by inputting Ctrl + D. 
Similarly to an actual shell program, enter executes the inputted command, and if nothing is inputted, the user is allowed to input a command again.
If an error is encountered when executing the command, an error message is given using perror. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "shell.h"

const int INPUTSIZE = 1000; // constant for the max length of all inputs

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
            // rewrite token array so the path/command name (ie the 0th index) isn't in it
            for(int i = 1; i < tokenc; i++){
                tokenv[i - 1] = tokenv[i];
            }
            // child executes command, exits if invalid
            execErr = execvp(pathFromTok, tokenv);
            if(execErr == -1){
                perror("Invalid command");
                exit(0);
            }
        }

        // parent
        else{
            wait(NULL); // parent waits
        }
    }
}

// gets the user input and puts it into the input string
// preconditions: the input string has not been filled
// params: the user input string
// returns: none
// postconditions: the input string is updated with the user input,
// if the user inputs an EOF, the program exits
void getInput(char *inputStr){
    int numTokens;
    printf("%s", "> ");
    inputStr = fgets(inputStr, INPUTSIZE * sizeof(char), stdin); // get user input
    // exits on EOF (Ctrl + D)
    if(inputStr == NULL){
        exit(0);
    }
}

// tokenizes the input string and puts each token into the tokenVector array
// preconditions: tokenVector has not been filled
// params: the user input string and an array of strings to be updated with the tokenized version of the user input
// returns: the number of tokens in the user input string
// postconditions: the tokenVector array is updated with the tokenized user input, with each token being an element in the vector
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
