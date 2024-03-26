#include <stdio.h>
#include <stdlib.h>

int stack[10];
int top = -1;
int size;
void push()
{
  int data;
  printf("Enter the data : ");
  scanf("%d", &data);
  if (top == size - 1)
  {
    printf("Overflow...");
  }
  else
  {
    top++;
    stack[top] = data;
  }
}
void pop()
{
  if (top == -1)
  {
    printf("Underflow...");
  }
  else
  {
    printf("Popping the data : %d", stack[top]);
    top--;
  }
}
void peek()
{
  printf("Peek is : %d", stack[top]);
}
void traverse()
{
  for (int i = top; i >= 0; i--)
  {
    printf(" %d", stack[i]);
  }
}
int main()
{
  int n;
  char ch;
  printf("Enter the size of Stack : ");
  scanf("%d", &size);
  do
  {

    printf("1. Push in stack\n");
    printf("2. Pop from stack\n");
    printf("3. Peek of stack\n");
    printf("4. Traverse stack\n");
    printf("Enter your choice : ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
      push();
      break;
    case 2:
      pop();
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