// Including necessary library
#include<stdio.h>

#define MAXSIZE 5

int queue[MAXSIZE];

int front = -1, rear = -1;

// Checking if Queue is empty
int isempty()
{

if(rear == -1)
return 1;

else

return 0;

}

// Checking if Queue is full
int isfull()
{

if(rear == MAXSIZE - 1)
return 1;

else

return 0;

}

// add element to the queue
void enqueue(int data)
{

if(isfull())

printf("Queue is full.\n");

else
{

if(isempty())
{

rear = front = 0;
queue[0] = data;

}
else

queue[++rear] = data;

}

}

// removing element from queue
int dequeue()
{

int data;
if(isempty())

printf("Queue is empty.\n");

else
{

data = queue[front++];
if(front > rear)

front = rear = -1;

return data;

}

}

// View the front element in queue
int peek()
{

if(isempty())

printf("Queue is empty.\n");
else

return queue[front];

}


int main()
{

enqueue(3);
enqueue(5);
enqueue(9);
enqueue(1);
enqueue(12);
printf("Element at front of the queue: %d\n", peek());
printf("Removed element: %d\n", dequeue());
printf("Removed element: %d\n", dequeue());
enqueue(15);
printf("Element at front of the queue: %d\n", peek());

}