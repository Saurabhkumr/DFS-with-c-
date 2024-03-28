#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void traverse();
void peek();

struct node
{
  int data;
  struct node *next;
};
struct node *top = NULL;
struct node *newnode;
struct node *temp;

int main()
{
  int n;
  char ch;
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

void push()
{
  newnode = (struct node *)malloc(sizeof(struct node));
  printf("Enter the element : ");
  scanf(" %d", &newnode->data);
  newnode->next = top;
  top = newnode;
}
void pop()
{
  temp = top;
  if (temp == NULL)
  {
    printf("Underflow...");
    return;
  }
  printf("Popped element is : %d", temp->data);
  top = top->next;
  free(temp);
}
void traverse()
{
  temp = top;
  while (temp != NULL)
  {
    printf(" %d", temp->data);
    temp = temp->next;
  }
}
void peek()
{
  printf("Peek element is : %d", top->data);
}