#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *next;
  int coef;
  int exp;
};
struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *temp1 = NULL;
struct node *temp2 = NULL;

void insert(struct node **start, int c, int e)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  newnode->coef = c;
  newnode->exp = e;
  if (*start == NULL || e > (*start)->exp)
  {
    newnode->next = *start;
    *start = newnode;
  }
  else
  {
    temp = *start;
    while (temp->next != NULL && temp->next->exp >= e)
    {
      temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
  }
}

void create(struct node **poly)
{
  int size;
  int c;
  int e;
  printf("Enter the size of polynomial: ");
  scanf("%d", &size);
  for (int i = 0; i < size; i++)
  {
    printf("Enter the coeff : ");
    scanf(" %d", &c);
    printf("Enter the exponenet : ");
    scanf(" %d", &e);
    insert(poly, c, e);
  }
}

void sum(struct node *poly1, struct node *poly2)
{
  temp1 = poly1;
  temp2 = poly2;
  struct node *start3 = NULL;
  while (temp1 != NULL && temp2 != NULL)
  {
    if (temp1->exp == temp2->exp)
    {
      insert(&start3, temp1->coef + temp2->coef, temp1->exp);
      temp1 = temp1->next;
      temp2 = temp2->next;
    }
    else if (temp1->exp > temp2->exp)
    {
      insert(&start3, temp1->coef, temp1->exp);
      temp1 = temp1->next;
    }
    else if (temp2->exp > temp1->exp)
    {
      insert(&start3, temp2->coef, temp2->exp);
      temp2 = temp2->next;
    }
  }
  while (temp1 != NULL)
  {
    insert(&start3, temp1->coef, temp1->exp);
    temp1 = temp1->next;
  }
  while (temp2 != NULL)
  {
    insert(&start3, temp2->coef, temp2->exp);
    temp2 = temp2->next;
  }
  printf("Added polynomial : ");
  display(start3);
}

void display(struct node *start)
{
  if (start == NULL)
    printf("Empty");

  struct node *temp = NULL;
  temp = start;
  while (temp != NULL)
  {
    printf(" %dx^%d", temp->coef, temp->exp);
    temp = temp->next;
    if (temp != NULL)
      printf(" + ");
    else
      printf("\n");
  }
}

int main()
{
  printf("Enter the first polynomial:\n");
  create(&start1);
  display(start1);
  printf("Enter the second polynomial:\n");
  create(&start2);
  display(start2);
  sum(start1, start2);
}
