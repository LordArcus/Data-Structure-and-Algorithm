// Including necessary library
#include <stdio.h>

// User define function
#include "mystack.h"

// Operations on Stack

// Check emptyness of stack
int isempty(int TOP){
    if(TOP == -1)
        return 1;
    return 0;
}


// Check if the stack is full
int isfull(int TOP, int MAX){
    if(TOP == MAX - 1) 
        return 1;
    return 0;
}


// Push the element to the stack
void push(char item, char *stack, int *TOP, int MAX) {
    if(isfull(*TOP, MAX)){
        printf("Stack is full\n");
    }
    else{
        (*TOP)++;
        stack[*TOP] = item;
    }
}

// Pop the element from stack
char pop(char *stack, int *TOP) {
    if(isempty(*TOP)){
        printf("Stack is empty\n");
    }
    else{
        char variable = stack[*TOP];
        (*TOP)--;
        return variable;
    }
}


// Peek the element in stack
char peek(char *stack, int *TOP) {
    if(isempty(*TOP)){
        printf("Stack is empty\n");
    }
    else{
        return stack[*TOP];
    }
}
