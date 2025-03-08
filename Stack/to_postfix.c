// Including necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// User-defined stack operations
#include "mystack.c"

// Define size of stack
#define MAX 20

// Define postfix_string and operator_string
char postfix_string[MAX];
char operator_string[MAX];

// Defining top for postfix string
int TOP_postfix = -1;

// Defining top for operator_string
int TOP_operator = -1; 

// Checking operators
int is_operator(char a){
    return (a == '+' || a == '-' || a == '*' || a == '/' || a == '^');
}

// Checking matching brackets
int is_matching(char left, char right) {
    return ((left == '(' && right == ')') || 
            (left == '{' && right == '}') || 
            (left == '[' && right == ']'));
}

// Main function
int main(void) {
    int len;

    // Ask user for length of expression
    printf("What is the length of your expression? ");
    scanf("%d", &len);
    
    // Allocate memory for expression
    char *expression = (char *)malloc((len + 1) * sizeof(char));
    
    // Asking users for an expression
    printf("Enter your expression: ");
    scanf("%s", expression); 

    // Looping through expression
    for(int i = 0; i < len; i++){
        if(isalpha(expression[i])) {
            // If the input is a variable (a-z, A-Z), push it to postfix_string
            push(expression[i], postfix_string, &TOP_postfix, MAX);
        }
        else if(is_operator(expression[i])) {
            // If the input is an operator, push it to operator_string
            push(expression[i], operator_string, &TOP_operator, MAX);
        }
        else if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            // If the input is a left bracket, push it to operator_string
            push(expression[i], operator_string, &TOP_operator, MAX);
        }
        else if(expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            // If the input is a right bracket, pop all operators until matching left bracket is found
            while (TOP_operator != -1 && !is_matching(operator_string[TOP_operator], expression[i])) {
                push(pop(operator_string, &TOP_operator), postfix_string, &TOP_postfix, MAX);
            }
            // Pop and discard the left bracket
            if (TOP_operator != -1) {
                pop(operator_string, &TOP_operator);
            }
        }
    }

    // Pop remaining operators into postfix_string
    while (TOP_operator != -1) {
        push(pop(operator_string, &TOP_operator), postfix_string, &TOP_postfix, MAX);
    }

    // Null-terminate the postfix string
    postfix_string[TOP_postfix + 1] = '\0';

    // Print the postfix expression
    printf("Postfix Expression: %s\n", postfix_string);

    // Free allocated memory
    free(expression);

    return 0;
}
