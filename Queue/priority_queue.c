#include <stdio.h>

#define MAXSIZE 5

int queue[MAXSIZE];
int priority[MAXSIZE];

int front = -1;
int rear = -1;

// Function to check if the queue is empty
int isempty() {
    if (rear == -1) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is full
int isfull() {
    if (rear == MAXSIZE - 1) {
        return 1;
    }
    return 0;
}

// Function to insert an element into the priority queue
void enqueue(int data, int prio) {
    if (isfull()) {
        printf("Queue is full.\n");
        return;
    }

    if (isempty()) {
        front = rear = 0;
        queue[rear] = data;
        priority[rear] = prio;
    } else {
        int i = rear;
        // Find the correct position to insert the element based on priority
        while (i >= front && priority[i] < prio) {
            queue[i + 1] = queue[i];
            priority[i + 1] = priority[i];
            i--;
        }
        queue[i + 1] = data;
        priority[i + 1] = prio;
        rear++;
    }
}

// Function to remove an element from the priority queue
int dequeue() {
    if (isempty()) {
        printf("Queue is empty.\n");
        return -1;
    }

    int data = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return data;
}

// Function to view the element at the front of the queue
int peek() {
    if (isempty()) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue[front];
}

int main() {
    enqueue(3, 1);  // Enqueue element with value 3 and priority 1
    enqueue(5, 3);  // Enqueue element with value 5 and priority 3
    enqueue(9, 2);  // Enqueue element with value 9 and priority 2
    enqueue(1, 4);  // Enqueue element with value 1 and priority 4
    enqueue(12, 0); // Enqueue element with value 12 and priority 0

    printf("Element at front of the queue: %d\n", peek());

    printf("Removed element: %d\n", dequeue());
    printf("Removed element: %d\n", dequeue());

    // Enqueue element with value 15 and priority 5
    enqueue(15, 5);  

    printf("Element at front of the queue: %d\n", peek());
    
    return 0;
}