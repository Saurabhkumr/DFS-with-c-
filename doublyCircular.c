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
struct node *tail;
struct node *temp1;

void display()
{
  temp = start;
  while (temp->next != start)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("%d", temp->data);
}
void sizeofDoubly()
{
  int count = 0;
  temp = start;
  if (start != NULL)
  {
    do
    {
      count++;
      temp = temp->next;
    } while (temp != start);
  }
  printf("Size of Doubly Linkedlist : %d", count);
}

void insert_start()
{
  printf("Enter the element : ");
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  scanf("%d", &newnode->data);
  newnode->next = start;
  start->prev = newnode;
  newnode->prev = tail;
  tail->next = newnode;
  start = newnode;
}
void insert_end()
{
  temp = start;
  printf("Enter the element : ");
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  scanf("%d", &newnode->data);
  tail->next = newnode;
  newnode->next = start;
  newnode->prev = tail;
  start->prev = newnode;
  tail = newnode;
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
  start->prev = tail;
  tail->next = start;
  free(temp);
}
void delete_end()
{
  temp = tail;
  tail = tail->prev;
  tail->next = start;
  start->prev = tail;
  free(temp);
}
void delete_pos()
{
  int pos;
  printf("enter the position you want to delete : ");
  scanf("%d", &pos);
  temp = start;
  for (int i = 0; i < pos - 1; i++)
  {
    temp = temp->next;
  }
  temp->next->prev = temp->prev;
  temp->prev->next = temp->next;
  temp1 = temp->next;
  free(temp);
}
void search()
{
  int target;
  int count = 1;
  int flag = 0;
  temp = start;
  printf("enter the target you want search : ");
  scanf("%d", &target);
  do
  {
    {
      if (temp->data == target)
      {
        printf("target element is at position : %d", count);
        flag = 1;
      }
      count++;
      temp = temp->next;
    }
  } while (temp != start);
  if (flag == 0)
  {
    printf("Not Found");
  }
}

void sort()
{
  int key;
  temp = start;
  do
  {
    {
      temp1 = temp->next;
      do
      {
        {
          if (temp->data > temp1->data)
          {
            key = temp->data;
            temp->data = temp1->data;
            temp1->data = key;
          }
          temp1 = temp1->next;
        }
      } while (temp1 != start);
      temp = temp->next;
    }
  } while (temp->next != start);
}
void reverse()
{
  struct node *curr = start;
  temp = NULL;
  do
  {
    temp = curr->next;
    curr->next = curr->prev;
    curr->prev = temp;
    curr = temp;
  } while (curr != start);
  tail = start;
  start = start->next;
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
      tail = newnode;
      newnode->next = start;
      newnode->prev = start;
    }
    else
    {
      // newnode->next = tail->next;
      // newnode->prev = tail;
      // tail->next->prev = newnode;
      // tail->next = newnode;
      // tail = newnode;
      tail->next = newnode;
      newnode->prev = tail;
      newnode->next = start;
      tail = newnode;
      start->prev = tail;
    }
  }
  do
  {
    printf("\n*********************************\n");
    printf("1.Display the Doubly Circular Linkedlist....\n");
    printf("2.Find the length of Doubly Circular linkedlist....\n");
    printf("3.Insertion at Starting....\n");
    printf("4.Insertion at Ending....\n");
    printf("5.Insertion at Specific position....\n");
    printf("6.Deletion from Starting....\n");
    printf("7.Deletion from Ending....\n");
    printf("8.Deletion from Specific position....\n");
    printf("9.Searching an element....\n");
    printf("10.Sorting....\n");
    printf("11.Reverse the Doubly Circular linkedlist....\n\n");

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