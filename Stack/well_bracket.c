// Code of algorithm that can find whether or not an expression is well-bracket

/*
    Logic:

    We need to implement stack to check whether an expression is well-bracket or not
    Stack has it's own funtions:
    Push
    Pop
    isempty
    isfull

    Now, the logic is we read all the element of the expression
    if we get any left bracket, we stored it in the stack
    if we get any right bracket:
        if stack is empty, expression is not well-bracket
        else, check whether top element in stack and this right bracket is equal
            if it is not, expression is not well-bracket
            else,
                we pop the top element from the stack

    else
     if stack is empty then, well bracket
     if not, then not well-bracket
*/

// Loading necessary library
#include <stdio.h>
#include <string.h>

// Stack size
#define Max 20

// Creating stack with array
int STACK[Max];

// Creating top variable. This variable will work as a pointer to access index of the element in an array.
int TOP = -1;


// Checking is the stack full
int isfull() {
    if (TOP == Max-1){
        return 1;
    }
    return 0;
}

// Checking is the stack empty
int isempty() {
    if (TOP == -1) {
        return 1;
    }
    return 0;
}


// Pushing element in the stack
int push(char a) {
    if (isfull()) {
        printf("Stack is full\n");
    }
    else {
        TOP++;
        STACK[TOP] = a;
    }
}


// Poping element out from the stack
char pop() {
    if(isempty()) {
        printf("Stack is empty\n");
    }
    else {
        char variable = STACK[TOP];
        TOP--;
        return variable;
    }
}

// Peeking element in the stack
char peek() {
    if(isempty()) {
        printf("Stack is empty\n");
    }
    else{
        return STACK[TOP];
    }
}

// Checking matching bracket
int is_matching(char left, char right) {
    if (left == '(' && right == ')' || left == '{' && right == '}' || left == '[' && right == ']'){
        return 1;
    }else {
        return 0;
    }
}




int main(void) {
    // size of input array
    int n = 15;

    // Creating array to store input values
    char expression[n];

    // Asking users a question for an expression
    printf("Do you have expression to check?\n");
    scanf("%s", expression);

    // checking length of string
    int length = strlen(expression);

    // Using for loop to access elements of this array
    for (int i = 0; i < length; i++) {

        // value in expression
        char current = expression[i];

        // Checking if expression has left bracket
        if (current == '(' || current == '{' || current == '[') {
            if(isfull()){
                printf("stack is full\n");
            }
            else {
                push(current);
            }
        } 
        
        // checking for right bracket
        if (current == ')' || current == '}' || current == ']') {

            if(isempty()){
                printf("Expression have unbalanced bracket\n");
                return 0;
            }

            // poping top element in stack
            char top = pop();

            // checking if top element is equal to current element
            if (!is_matching(top, current)){
                printf("Expression have unbalanced bracket\n");
                return 0;
            }
        }
    }

    // Checking codition of expression after looping through all the element
    if(!isempty()){
        printf("Expression have unbalanced bracket\n");
        return 0;
    }
    else {
        printf("Expression is balanced\n");
    }

}
