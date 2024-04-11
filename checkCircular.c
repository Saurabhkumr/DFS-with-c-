#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *next;
  int data;
};
struct node *tail;
struct node *start;
struct node *temp;

int check()
{
  struct node *slow = start;
  struct node *fast = start;
  while (slow != NULL && fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return 1;
  }
  return 0;
}
int main()
{
  int size, cont;
  char ch;
  int choice;
  struct node *newnode;
  printf("Enter the size : ");
  scanf("%d", &size);
  for (int i = 0; i < size; i++)
  {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the element : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (start == NULL)
    {
      start = newnode;
      temp = newnode;
    }
    else
    {
      temp->next = newnode;
      temp = newnode;
    }
  }
  printf(" %d", check());
}