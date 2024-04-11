#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int top = -1;
char stack[10];

void push(char c)
{
  if (top == 10 - 1)
  {
    printf("Stack overflow\n");
    return;
  }
  stack[++top] = c;
}

char pop()
{
  if (top == -1)
  {
    printf("Stack underflow\n");
    return;
  }
  return stack[top--];
}

int isEmpty()
{
  return top == -1;
}

char peek()
{
  if (top == -1)
  {
    printf("\nStack underflow\n");
    return;
  }
  return stack[top];
}

int precedence(char op)
{
  switch (op)
  {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  default:
    return 0;
  }
}

void posteval(char *infix, char *postfix)
{
  int i, j = 0;
  char popped;
  for (i = 0; infix[i] != '\0'; i++)
  {
    if (isalnum(infix[i]))
    {
      postfix[j] = infix[i];
      j++;
    }
    else if (infix[i] == '(')
    {
      push(infix[i]);
    }
    else if (infix[i] == ')')
    {
      while ((popped = pop()) != '(')
      {
        postfix[j] = popped;
        j++;
      }
    }
    else
    {
      while (!isEmpty() && precedence(peek()) >= precedence(infix[i]))
      {
        postfix[j] = pop();
        j++;
      }
      push(infix[i]);
    }
  }
  while (!isEmpty())
  {
    postfix[j] = pop();
    j++;
  }
  postfix[j] = '\0';
}
int main()
{
  char infix[10];
  char postfix[10];
  printf("enter the expersion : ");
  gets(infix);
  posteval(infix, postfix);
  printf("\nPostfix expression: %s\n", postfix);
  return 0;
}