#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *next;
  struct node *prev;
  int data;
};

int main()
{
  int size;
  struct node *newnode;
  struct node *start = NULL;
  struct node *temp;
  printf("Enter the size of Doubly Linkedlist : ");
  scanf("%d", &size);
  for (int i = 0; i < size; i++)
  {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the elements : ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    if (start == NULL)
    {
      start = newnode;
      temp = newnode;
    }
    else
    {
      temp->next = newnode;
      newnode->prev = temp;
      temp = newnode;
    }
  }

  // display
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->prev;
  }
}