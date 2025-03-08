// Use of malloc, calloc and realloc to calculate sum and average of given numbers.

#include <stdio.h>
#include <stdlib.h>


int main(void){

    // define the variable to stores number
    int * numbers;
    int i, n, sum = 0;
    float avg;

    // Asking users for total number
    printf("How many numbers do you have to calculate sum and average?\n");

    // storing total number to n
    scanf("%d", &n);

    // Using malloc to specify size of numbers
    numbers = (int *)malloc(n * sizeof(int));

    /*
        // Using Calloc
        numbers = (int *)calloc(n, sizeof(int));
    */

    // Asking user for numbers
    printf("Enter %d numbers one by one\n", n);

    // loop to scan all the number
    for(i =0; i < n; i++){
        scanf("%d", &numbers[i]);
    }

   // Calculating Sum
   printf("your numbers are given below:\n");
   for(i =0; i < n; i++){
   sum += numbers[i];
   }

   // Calculating Average
   avg = (float)sum / n;

   // printing sum and avearage
   printf("Sum of your numbers is: %d\n", sum);
   printf("Average of your numbers is: %.2f\n", avg);

   // Now using  realloc
   int extra;

   printf("How many extra numbers do you want to add?\n");
   scanf("%d", &extra);

   // Reallocating memory to add extra numbers
   numbers = (int *)realloc(numbers, (n + extra) * sizeof(int));

   // Asking user for extra numbers
   printf("Enter %d extra numbers one by one\n", extra);

   // Scan  extra numbers
   for(i = n; i < n+ extra; i++){
    scanf("%d", &numbers[i]);
   }

   // for loop again for calculating sum of extra numbers
   for(i = n; i < n + extra; i++){
        sum += numbers[i];
    }

    // Calculating average
    avg = (float)sum / (n + extra);

    // Printing updated sum and average
    printf("Updated Sum of your numbers is: %d\n", sum);
    printf("Updated average: %.2f", avg);

    free(numbers);

}