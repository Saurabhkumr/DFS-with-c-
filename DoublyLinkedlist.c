#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *next;
  struct node *prev;
  int data;
};
struct node *start = NULL;
struct node *temp;
struct node *temp1;

void display()
{
  temp = start;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}
void sizeofDoubly()
{
  int count = 0;
  temp = start;
  while (temp != NULL)
  {
    count++;
    temp = temp->next;
  }
  printf("Size of Doubly Linkedlist : %d", count);
}

void insert_start()
{
  temp = start;
  printf("Enter the element : ");
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  scanf("%d", &newnode->data);
  newnode->next = temp;
  temp->prev = newnode;
  newnode->prev = NULL;
  start = newnode;
}
void insert_end()
{
  temp = start;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  printf("Enter the element : ");
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  scanf("%d", &newnode->data);
  temp->next = newnode;
  newnode->prev = temp;
  newnode->next = NULL;
}
void insert_pos()
{
  int pos;
  printf("enter the position you want to insert : ");
  scanf("%d", &pos);
  temp = start;
  for (int i = 0; i < pos - 2; i++)
  {
    temp = temp->next;
  }
  printf("Enter the element : ");
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  scanf("%d", &newnode->data);
  newnode->next = temp->next;
  temp->next->prev = newnode;
  temp->next = newnode;
  newnode->prev = temp;
}
void delete_start()
{
  temp = start;
  start = temp->next;
  temp->next->prev = NULL;
  free(temp);
}
void delete_end()
{
  temp = start;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->prev->next = NULL;
  free(temp);
}
void delete_pos()
{
  int pos;
  printf("enter the position you want to delete : ");
  scanf("%d", &pos);
  temp = start;
  for (int i = 0; i < pos - 2; i++)
  {
    temp = temp->next;
  }
  temp1 = temp->next;
  temp->next = temp1->next;
  temp1->next->prev = temp;
  free(temp1);
}
void search()
{
  int target;
  int count = 1;
  int flag = 0;
  temp = start;
  printf("enter the targetent you want search : ");
  scanf("%d", &target);
  while (temp != NULL)
  {
    if (temp->data == target)
    {
      printf("target element is at position : %d", count);
      flag = 1;
    }
    count++;
    temp = temp->next;
  }
  if (flag == 0)
  {
    printf("Not Found");
  }
}

void sort()
{
  int key;
  temp = start;
  while (temp != NULL)
  {
    temp1 = temp->next;
    while (temp1 != NULL)
    {
      if (temp->data > temp1->data)
      {
        key = temp->data;
        temp->data = temp1->data;
        temp1->data = key;
      }
      temp1 = temp1->next;
    }
    temp = temp->next;
  }
}

void reverse()
{
  struct node *current = start;
  temp = NULL;
  while (current != NULL)
  {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }
  start = temp->prev;
}

int main()
{
  int size, ch;
  char cont;
  struct node *newnode;
  printf("Enter the size of Doubly Linkedlist : ");
  scanf("%d", &size);
  for (int i = 0; i < size; i++)
  {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element : ");
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
  do
  {
    printf("\n*********************************\n");
    printf("1.Display the Doubly Linkedlist....\n");
    printf("2.Find the length of Doubly linkedlist....\n");
    printf("3.Insertion at Starting....\n");
    printf("4.Insertion at Ending....\n");
    printf("5.Insertion at Specific position....\n");
    printf("6.Deletion from Starting....\n");
    printf("7.Deletion from Ending....\n");
    printf("8.Deletion from Specific position....\n");
    printf("9.Searching an element....\n");
    printf("10.Sorting....\n");
    printf("11.Reverse the Doubly linkedlist....\n\n");

    printf("Enter your choice : ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      // display
      display();
      break;

    case 2:
      sizeofDoubly();
      break;
    case 3:
      insert_start();
      display();
      break;
    case 4:
      insert_end();
      display();
      break;
    case 5:
      insert_pos();
      display();
      break;
    case 6:
      delete_start();
      display();
      break;
    case 7:
      delete_end();
      display();
      break;
    case 8:
      delete_pos();
      display();
      break;
    case 9:
      search();
      break;
    case 10:
      sort();
      display();
      break;
    case 11:
      reverse();
      display();
      break;

    default:
      break;
    }
    printf("\nWant to continue (y/n):");
    scanf(" %c", &cont);
  } while (cont == 'y');
}