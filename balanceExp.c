#include <stdio.h>
#include <stdlib.h>
int top = -1;
char stack[6];
void push(char ch)
{
  if (top == 5)
  {
    printf("Overflow");
  }
  else
  {
    top++;
    stack[top] = ch;
  }
}

void pop()
{
  if (top < 0)
  {
    printf("Underflow");
  }
  else
  {
    top--;
  }
}
int main()
{
  int flag = 0;
  char arr[10];
  
  for (int i = 0; i < 6; i++)
  {

    if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
    {
      push(arr[i]);
    }
    else if (stack[top] == '(' && arr[i] == ')')
    {
      pop();
    }
    else if (stack[top] == '{' && arr[i] == '}')
    {
      pop();
    }
    else if (stack[top] == '[' && arr[i] == ']')
    {
      pop();
    }
    else
    {
      flag = 1;
      break;
    }
  }
  if (flag == 0)
    printf("Balanced Expression !");
  else
    printf("Unbalanced Expression !");
}
