// Including necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Define maximum size for the stack
#define MAX 20

// Stack structure
int stack[MAX];
int TOP = -1;

// Function to push an element onto the stack
void push(int value) {
    if (TOP == MAX - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack[++TOP] = value;
}

// Function to pop an element from the stack
int pop() {
    if (TOP == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack[TOP--];
}

// Function to evaluate postfix expression
int evaluate_postfix(char *expression) {
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            // Convert character digit to integer and push onto stack
            push(expression[i] - '0');
        } 
        else {
            // Pop two operands
            int operand2 = pop();
            int operand1 = pop();

            // Perform operation based on the operator
            switch (expression[i]) {
                case '+': push(operand1 + operand2); break;
                case '-': push(operand1 - operand2); break;
                case '*': push(operand1 * operand2); break;
                case '/': 
                    if (operand2 == 0) {
                        printf("Division by zero error!\n");
                        exit(1);
                    }
                    push(operand1 / operand2); 
                    break;
                case '^': push((int)pow(operand1, operand2)); break;
                default: 
                    printf("Invalid operator: %c\n", expression[i]);
                    exit(1);
            }
        }
    }
    // The final result will be the only element left in the stack
    return pop();
}

// Main function
int main() {
    char expression[MAX];

    // Asking user for postfix expression
    printf("Enter a valid postfix expression: ");
    scanf("%s", expression);

    // Evaluate postfix expression
    int result = evaluate_postfix(expression);
    printf("Result: %d\n", result);

    return 0;
}
