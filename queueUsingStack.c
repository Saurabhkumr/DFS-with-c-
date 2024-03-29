#include <stdio.h>

int s1[10], s2[10];
int top1 = -1, top2 = -1;
int count = 0;
int a, b;
void push1(int data)
{
  if (top1 == 9)
  {
    printf("Overflow..");
  }
  else
  {
    top1++;
    s1[top1] = data;
  }
}
int pop1()
{
  if (top1 == -1)
  {
    printf("underflow");
  }
  else
  {
    return s1[top1--];
  }
}
void push2(int data)
{
  if (top2 == 9)
  {
    printf("overflow");
  }
  else
  {
    top2++;
    s2[top2] = data;
  }
}
int pop2()
{
  if (top2 == -1)
  {
    printf("underflow");
  }
  else
  {
    return s2[top2--];
  }
}
void enqueue(int data)
{
  push1(data);
  count++;
}
void dequeue()
{
  for (int i = 0; i < count; i++)
  {
    a = pop1();
    push2(a);
  }
  b = pop2();
  printf("dequeued data is : %d", b);
  count--;
  for (int i = 0; i < count; i++)
  {
    b = pop2();
    push1(b);
  }
}
void display()
{

  printf("\nElemnt in queue : ");
  for (int i = 0; i < count; i++)
  {
    printf(" %d", s1[i]);
  }
}

int main()
{
  enqueue(10);
  enqueue(20);
  enqueue(30);
  dequeue();
  enqueue(40);
  display();
}