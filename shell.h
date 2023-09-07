#ifndef SHELL
#define SHELL

#define TRUE 1
#define FALSE 0
#define EMPTY -INT32_MAX

int tokenize(char *input, char ***token_vector);
void getInput(char *inputStr);

#endif