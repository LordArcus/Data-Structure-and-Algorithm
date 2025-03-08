// This is the header file for stack

#ifndef MYSTACK_H
#define MYSTACK_H


// Function Prototypes (declarations)
int isempty(int TOP);
int isfull(int TOP, int MAX);
void push(char item, char *stack, int *TOP, int MAX);
char pop(char *stack, int *TOP);
char peek(char *stack, int *TOP);

#endif