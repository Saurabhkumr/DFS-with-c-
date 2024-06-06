#include <stdio.h>
#include <stdlib.h>

// Node structure containing power and coefficient of variable
struct node
{
  int coef;
  int exp;
  struct node *next;
};

struct node *start1 = NULL;
struct node *start2 = NULL;

// Function to create new node and insert it into the polynomial linked list
void insert(struct node **start, int c, int e)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->coef = c;
  newnode->exp = e;
  newnode->next = NULL;

  if (*start == NULL || e > (*start)->exp)
  {
    newnode->next = *start;
    *start = newnode;
  }
  else
  {
    struct node *temp = *start;
    while (temp->next != NULL && temp->next->exp >= e)
    {
      temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
  }
}

// Function to create a polynomial by reading coefficients and exponents
void create(struct node **poly)
{
  int size;
  int c;
  int e;
  printf("Enter the size of polynomial: ");
  scanf("%d", &size);
  for (int i = 0; i < size; i++)
  {
    printf("Enter the coefficient: ");
    scanf("%d", &c);
    printf("Enter the exponent: ");
    scanf("%d", &e);
    insert(poly, c, e);
  }
}

// Function to add two polynomials and return the result
struct node *sum(struct node *poly1, struct node *poly2)
{
  struct node *start3 = NULL;

  while (poly1 != NULL && poly2 != NULL)
  {
    if (poly1->exp == poly2->exp)
    {
      insert(&start3, poly1->coef + poly2->coef, poly1->exp);
      poly1 = poly1->next;
      poly2 = poly2->next;
    }
    else if (poly1->exp > poly2->exp)
    {
      insert(&start3, poly1->coef, poly1->exp);
      poly1 = poly1->next;
    }
    else
    {
      insert(&start3, poly2->coef, poly2->exp);
      poly2 = poly2->next;
    }
  }

  while (poly1 != NULL)
  {
    insert(&start3, poly1->coef, poly1->exp);
    poly1 = poly1->next;
  }

  while (poly2 != NULL)
  {
    insert(&start3, poly2->coef, poly2->exp);
    poly2 = poly2->next;
  }

  return start3;
}

// Function to display the polynomial
void display(struct node *start)
{
  if (start == NULL)
  {
    printf("Empty\n");
    return;
  }

  struct node *temp = start;
  while (temp != NULL)
  {
    printf("%dx^%d", temp->coef, temp->exp);
    temp = temp->next;
    if (temp != NULL)
    {
      printf(" + ");
    }
  }
  printf("\n");
}

// Driver code
int main()
{
  printf("Enter the first polynomial:\n");
  create(&start1);
  display(start1);

  printf("Enter the second polynomial:\n");
  create(&start2);
  display(start2);

  struct node *result = sum(start1, start2);
  printf("Added polynomial: ");
  display(result);

  return 0;
}
