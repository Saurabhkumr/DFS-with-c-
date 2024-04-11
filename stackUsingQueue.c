// STACK USING QUEUE
#include <stdio.h>
#include <stdlib.h>
int size;
int front = -1;
int rear = -1;
int front1 = -1;
int rear1 = -1;
int count = 0;
int q1[10];
int q2[10];

void push()
{
  int data;
  printf("enter the data: ");
  scanf("%d", &data);
  if (rear == 9)
  {
    printf("Overflow");
  }
  else if (front == -1 && rear == -1)
  {
    front = 0;
    rear = 0;
    q1[rear] = data;
    count++;
  }
  else
  {
    rear++;
    q1[rear] = data;
    count++;
  }
}
void pop()
{
  pop1();
  swap();
}

void pop1()
{

  for (int i = 0; i < count - 1; i++)
  {
    int a = dequeue();
    push1(a);
  }
  dequeue();
}
void push1(int ele)
{
  if (rear1 == 9)
  {
    printf("Overflow");
  }
  else if (front1 == -1 && rear1 == -1)
  {
    front1 = 0;
    rear1 = 0;
    q2[rear1] = ele;
  }
  else
  {
    rear1++;
    q2[rear1] = ele;
  }
}

void swap()
{
  for (int i = 0; i <= rear1; i++)
  {
    int b = pop2();
    push2(b);
  }
}
int pop2()
{
  int c;
  if (front1 == -1 && rear1 == -1)
  {
    printf("Underflow");
  }
  else if (front1 == rear1)
  {
    c = q2[front1];
    front1 = -1;
    rear1 = -1;
  }
  else
  {
    c = q2[front1];
    front1++;
  }
  return c;
}
void push2(int d)
{
  if (rear == 9)
  {
    printf("Overflow");
  }
  else if (front == -1 && rear == -1)
  {
    front = 0;
    rear = 0;
    q1[rear] = d;
  }
  else
  {
    rear++;
    q1[rear1] = d;
  }
}

void display()
{
  if (front == -1 && rear == -1)
  {
    printf("Empty queue");
  }
  else
  {

    for (int i = front; i <= rear; i++)
    {
      printf(" %d", q1[i]);
    }
  }
}

int main()
{
  printf("STACK USING QUEUE\n");
  printf("enter size of stack:");
  scanf("%d", &size);
  int k;
  do
  {
    printf("press 1 to push in stack\n");
    printf("press 2 to pop from stack\n");
    printf("press 3 to display stack\n");

    printf("enter your choice:");
    scanf("%d", &k);
    switch (k)
    {
    case 1:

      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    }
  } while (k != 0);
  return 1;
}