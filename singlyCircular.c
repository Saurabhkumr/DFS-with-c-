#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *next;
  int data;
};

struct node *temp = NULL;
struct node *temp1 = NULL;

struct node *tail = NULL;
int pos, i;

// display
void display()
{
  temp = tail->next;
  do
  {
    printf("%d ", temp->data);
    temp = temp->next;
  } while (temp != tail->next);
}

void count()
{
  temp = tail->next;
  if (temp == NULL)
  {
    printf("size is 0");
    return;
  }

  int count = 1;
  while (temp->next != tail->next)
  {
    count++;
    temp = temp->next;
  }
  printf("Size of Singly circular linkedlist is %d", count);
}

void insert_start()
{

  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  printf("Enter the element you want to enter : ");
  scanf("%d", &newnode->data);
  newnode->next = tail->next;
  tail->next = newnode;
}
void insert_end()
{

  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  printf("Enter the element you want to enter : ");
  scanf("%d", &newnode->data);
  newnode->next = tail->next;
  tail->next = newnode;
  tail = newnode;
}
void insert_pos()
{
  i = 1;

  printf("Enter the position you want to insert the element : ");
  scanf("%d", &pos);
  if (pos == 1)
  {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element you want to enter : ");
    scanf("%d", &newnode->data);
    newnode->next = tail->next;
    tail->next = newnode;
    return;
  }
  temp = tail->next;
  while (i < pos - 1)
  {
    temp = temp->next;
    i++;
  }
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  printf("Enter the element you want to enter : ");
  scanf("%d", &newnode->data);
  newnode->next = temp->next;
  temp->next = newnode;
}
void delete_start()
{
  temp = tail->next;
  tail->next = temp->next;
  free(temp);
}
void delete_end()
{
  temp = tail->next;
  while (temp->next->next != tail->next)
  {
    temp = temp->next;
  }
  temp->next = tail->next;
  free(tail);
  tail = temp;
}
void delete_pos()
{
  struct node *temp1;
  printf("Enter the position of element you want to delete : ");
  scanf("%d", &pos);
  i = 1;
  temp = tail->next;
  while (i < pos - 1)
  {
    temp = temp->next;
    i++;
  }
  temp1 = temp->next;
  temp->next = temp1->next;
  free(temp1);
}
void search()
{
  int target;
  printf("Enter the element you want to search : ");
  scanf("%d", &target);
  int count = 0;
  int flag = 0;
  temp = tail->next;
  do
  {
    if (temp->data == target)
    {
      printf("Element is at index : %d", count);
      flag = 1;
    }
    count++;
    temp = temp->next;
  } while (temp != tail->next);
  if (flag == 0)
  {
    printf("Not Found !");
  }
}

// Sorting

void sort()
{
  int key;
  temp = tail->next;
  do
  {
    temp1 = temp->next;
    while (temp1 != tail->next)
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
  } while (temp != tail->next);
}
void reverse()
{
  struct node *current = tail->next;
  struct node *prev = tail;
  struct node *next = NULL;
  tail = tail->next;

  do
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  } while (current != tail);
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
    printf("Enter the element : ");
    scanf("%d", &newnode->data);
    if (tail == NULL)
    {
      tail = newnode;
      newnode->next = tail;
    }
    else
    {
      newnode->next = tail->next;
      tail->next = newnode;
      tail = newnode;
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
      count();
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