#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // Define the size of the queue

// Queue variables
int items[SIZE];
int front = -1;
int rear = -1;

// Function to add an element to the queue
void enqueue(int value)
{
  // Check if the queue is full
  if ((rear + 1) % SIZE == front)
  {
    printf("Queue is full\n");
    return;
  }

  if (front == -1)
  {
    front = 0;
  }

  rear = (rear + 1) % SIZE;
  items[rear] = value;
  printf("Inserted %d\n", value);
}

// Function to remove an element from the queue
int dequeue()
{
  // Check if the queue is empty
  if (front == -1)
  {
    printf("Queue is empty\n");
    return -1;
  }

  int item = items[front];
  if (front == rear)
  {
    // The queue is now empty
    front = -1;
    rear = -1;
  }
  else
  {
    front = (front + 1) % SIZE;
  }
  return item;
}

// Function to display the elements of the queue
void display()
{
  // Check if the queue is empty
  if (front == -1)
  {
    printf("Queue is empty\n");
    return;
  }

  printf("Queue elements are:\n");
  int i = front;
  while (1)
  {
    printf("%d ", items[i]);
    if (i == rear)
    {
      break;
    }
    i = (i + 1) % SIZE;
  }
  printf("\n");
}

// Main function to test the circular queue
int main()
{
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50); // Queue is full here

  display();

  printf("Dequeued: %d\n", dequeue());
  display();

  enqueue(60);
  display();

  return 0;
}
