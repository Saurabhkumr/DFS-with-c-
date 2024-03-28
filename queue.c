#include <stdio.h>
#include <stdlib.h>
int queue[10];
int front = -1;
int rear = -1;
int size;

void enqueue()
{
  int data;
  printf("Enter the element : ");
  scanf(" %d", &data);
  if (rear == size - 1)
  {
    printf("Overflow");
  }
  else if (front == -1 && rear == -1)
  {
    rear = 0;
    front = 0;
    queue[rear] = data;
  }
  else
  {
    rear++;
    queue[rear] = data;
  }
}

void dequeue()
{
  if (front == -1 && rear == -1)
  {
    printf("Underflow");
  }
  else if (front == rear)
  {
    printf("Enqueue data is : %d", queue[front]);
    front = -1;
    rear = -1;
  }
  else
  {
    printf("Enqueue data is : %d", queue[front]);
    front++;
  }
}

void traverse()
{
  if (front == -1 && rear == -1)
  {
    printf("Empty queue");
  }
  else
  {

    for (int i = front; i <= rear; i++)
    {
      printf(" %d", queue[i]);
    }
  }
}
void peek()
{
  if (front == NULL)
  {
    printf("Empty queue");
  }
  else
    printf("Peek element id : %d", queue[front]);
}

int main()
{
  int n;
  char ch;
  printf("Enter the size of Queue : ");
  scanf("%d", &size);
  do
  {

    printf("1. Enqueue in Queue\n");
    printf("2. Dequeue from Queue\n");
    printf("3. Peek of Queue\n");
    printf("4. Traverse Queue\n");
    printf("Enter your choice : ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
      enqueue();
      break;
    case 2:
      dequeue();
      break;
    case 3:
      peek();
      break;
    case 4:
      traverse();
      break;

    default:
      break;
    }

    printf("\nWant to continue(y/n)...");
    scanf(" %c", &ch);
  } while (ch == 'y');
}
