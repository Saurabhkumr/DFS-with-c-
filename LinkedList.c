#include <stdlib.h>
#include <stdio.h>

struct node
{
  int value;
  struct node *next;
};

// Display

void display(struct node *start)
{
  struct node *temp;
  temp = start;
  while (temp != NULL)
  {
    printf("%d ", temp->value);
    temp = temp->next;
  }
}

// Length of linkedlist
int length(struct node *start)
{
  int count = 0;
  struct node *temp;
  temp = start;
  while (temp != NULL)
  {
    count++;
    temp = temp->next;
  }
  return count;
}

// Insertion at starting
void insert_start(struct node **start)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  printf("Enter the element you want to insert : ");
  scanf("%d", &newnode->value);
  newnode->next = *start;
  *start = newnode;
}

// Insertion at end
void insert_end(struct node **start)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  struct node *temp = *start;
  printf("Enter the element you want to enter : ");
  scanf("%d", &newnode->value);
  if (*start == NULL)
  {
    *start = newnode;
    return;
  }
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newnode;
  newnode->next = NULL;
}

// Insertion at specific position
void insert_pos(struct node *start, int pos)
{
  struct node *temp = start;
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  for (int i = 0; i < pos - 2; i++)
  {
    temp = temp->next;
  }
  printf("Enter the element :");
  scanf("%d", &newnode->value);
  newnode->next = temp->next;
  temp->next = newnode;
}

// Deletion from start
void delete_start(struct node **start)
{
  struct node *temp = *start;
  *start = temp->next;
}

// Deletion from end
void delete_end(struct node **start)
{
  struct node *temp = *start;
  while (temp->next->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = NULL;
}
// Delete from specific position

void delete_pos(struct node *start, int pos)
{
  struct node *temp = start;
  for (int i = 0; i < pos - 2; i++)
  {
    temp = temp->next;
  }

  struct node *temp1 = temp->next;
  temp->next = temp1->next;
  free(temp1);
}

// Searching
void search(struct node *start)
{
  int target;
  printf("Enter the element you want to search : ");
  scanf("%d", &target);
  struct node *temp = start;
  int count = 0;
  int flag = 0;
  while (temp != NULL)
  {
    if (temp->value == target)
    {
      printf("Element is at index : %d", count);
      flag = 1;
    }
    count++;
    temp = temp->next;
  }
  if (flag == 0)
  {
    printf("Not Found !");
  }
}

// Sorting

void sort(struct node *start)
{
  int key;
  struct node *temp = start;
  struct node *temp1;
  while (temp != NULL)
  {
    temp1 = temp->next;
    while (temp1 != NULL)
    {
      if (temp->value > temp1->value)
      {
        key = temp->value;
        temp->value = temp1->value;
        temp1->value = key;
      }
      temp1 = temp1->next;
    }
    temp = temp->next;
  }
}

// Reverse the linkedlist

void reverse(struct node **start)
{
  struct node *current = *start;
  struct node *prev = NULL;
  struct node *next = NULL;

  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *start = prev;
}

int main()
{

  struct node *newnode;
  struct node *start = NULL;
  int size;
  int pos;
  int choice;
  char cont;
  struct node *temp;
  printf("enter the number of element : ");
  scanf("%d", &size);

  // Create the Linkedlist

  for (int i = 0; i < size; i++)
  {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the element : ");
    scanf("%d", &newnode->value);
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

  printf("\n*********************************\n");
  printf("1.Display the Linkedlist....\n");
  printf("2.Find the length of linkedlist....\n");
  printf("3.Insertion at Starting....\n");
  printf("4.Insertion at Ending....\n");
  printf("4.Insertion at Ending....\n");
  printf("5.Insertion at Specific position....\n");
  printf("6.Deletion from Starting....\n");
  printf("7.Deletion from Ending....\n");
  printf("8.Deletion from Specific position....\n");
  printf("9.Searching an element....\n");
  printf("10.Sorting....\n");
  printf("11.Reverse the linkedlist....\n\n");

  do
  {
    printf("Choose the above option to perform any operation : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      display(start);
      break;
    case 2:
      printf("%d ", length(start));
      break;
    case 3:
      insert_start(&start);
      display(start);
      break;
    case 4:
      insert_end(&start);
      display(start);
      break;
    case 5:
      printf("Enter the position : ");
      scanf("%d", &pos);
      insert_pos(start, pos);
      display(start);
      break;
    case 6:
      delete_start(&start);
      display(start);
      break;
    case 7:
      delete_end(&start);
      display(start);
      break;
    case 8:
      printf("Enter the position : ");
      scanf("%d", &pos);
      delete_pos(start, pos);
      display(start);
      break;
    case 9:
      search(start);
      break;
    case 10:
      sort(start);
      display(start);
      break;
    case 11:
      reverse(&start);
      display(start);
      break;

    default:
      break;
    }

    printf("\nWant to continue (y/n):");
    scanf(" %c", &cont);
  } while (cont == 'y');
}