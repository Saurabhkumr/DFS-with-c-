#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *next;
  int data;
};
struct node *newnode;
struct node *front = NULL;
struct node *rear = NULL;
struct node *temp;

void enqueue()
{
  newnode = (struct node *)malloc(sizeof(struct node));
  printf("Enter the data : ");
  scanf(" %d", &newnode->data);
  newnode->next = NULL;
  if (front == NULL && rear == NULL)
  {
    front = rear = newnode;
  }
  else
  {
    rear->next = newnode;
    rear = newnode;
  }
}
void dequeue()
{
  temp = front;
  if (front == NULL && rear == NULL)
  {
    printf("Empty queue");
  }
  else if (front == rear)
  {
    front = rear = NULL;
    printf("Dequeue element is : %d", temp->data);
    free(temp);
  }
  else
  {
    front = front->next;
    printf("Dequeue element is : %d", temp->data);
    free(temp);
  }
}
void traverse()
{
  temp = front;
  if (front == NULL && rear == NULL)
  {
    printf("Underflow");
  }
  else
  {
    while (temp != NULL)
    {
      printf(" %d", temp->data);
      temp = temp->next;
    }
  }
}
void peek()
{
  printf("Peek element is %d", front->data);
}

int main()
{
  int n;
  char ch;
  do
  {

    printf("1. Enqueue in Queue\n");
    printf("2. Dequeue from Queue\n");
    printf("3. Peek of Queue\n");
    printf("4. Traverse Queue\n");
    printf("Enter your choice : ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
      enqueue();
      break;
    case 2:
      dequeue();
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
