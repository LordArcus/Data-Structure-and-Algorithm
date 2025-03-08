// Including necessary library
#include <stdio.h>

#define MAXSIZE 5

int queue[MAXSIZE];

int front = -1;
int rear = -1;

// Checking if the queue is empty
int isempty()
{

if(rear == -1)
return 1;

else

return 0;

}

// Checking if the queue is full
int isfull()
{

if((rear + 1) % MAXSIZE == front)

return 1;

else

return 0;

}

// Inserting an element into the queue
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
{

rear = (rear + 1) % MAXSIZE;

queue[rear] = data;

}

}

}

// removing an element from the queue
int dequeue()
{

int data;
if(isempty())

printf("Queue is empty.\n");

else
{

data = queue[front];

if(front == rear)

front = rear = -1;

else

front = (front + 1) % MAXSIZE;

}
return data;

}


// view element in queue
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