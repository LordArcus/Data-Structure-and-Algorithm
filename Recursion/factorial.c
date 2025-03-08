/*
logic: if n is given by user, then code needs to calculate n!. How?

We know, 
0! = 1
1! = 1
2! = 1 * 2
3! = 1 * 2 * 3
and so on upto n as:
n! = 1 * 2 * 3 ... * n-1 * n

observing the patterns, we can say this is recursion problem
n! = (n-1) * n

*/


// Including necessary library
#include <stdio.h>


/*
Calculation of factorial using iteration

int main(void) {
    int n;
    long factorial = 1;

    // Asking user for number to calculate it's factorial
    printf("Enter a number: ");
    scanf("%d", &n);

    // loop to calculate factorial
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    printf("Factorial of %d is: %ld\n", n, factorial);
}

*/

// By recursion
int factorial(int n){
    if (n == 0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

int main(void){
    int number;
    long factorial;
    
    // Asking user for number
    while(number < 0){
        printf("Enter the number: ");
        scanf("%d", &number);
    }
}