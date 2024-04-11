#include <stdio.h>
#include <stdlib.h>
// Stack implementation
int stack[10];
int top = -1;
void push(int item)
{
  if (top >= 9)
  {
    printf("Stack Overflow\n");
    return;
  }
  top++;
  stack[top] = item;
}
int pop()
{
  if (top < 0)
  {
    printf("Stack Underflow\n");
    return -1;
  }
  int item = stack[top];
  top--;
  return item;
}

int evaluate(char *expression)
{
  int i = 0;
  char symbol = expression[i];
  int operand1, operand2, result;

  while (symbol != '\0')
  {
    if (symbol >= '0' && symbol <= '9')
    {
      int num = symbol - '0';
      push(num);
    }
    else
    {
      operand2 = pop();
      operand1 = pop();
      switch (symbol)
      {
      case '+':
        result = operand1 + operand2;
        break;
      case '-':
        result = operand1 - operand2;
        break;
      case '*':
        result = operand1 * operand2;
        break;
      case '/':
        result = operand1 / operand2;
        break;
      }
      push(result);
    }
    i++;
    symbol = expression[i];
  }
  result = pop();
  return result;
}

int main()
{
  char expression[] = "231*+9-";
  int result = evaluate(expression);
  printf("Result= %d\n", result);
  return 0;
}