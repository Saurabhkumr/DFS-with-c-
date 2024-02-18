#include <stdlib.h>
#include <stdio.h>

void removeDuplicate(int *arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (*(arr + i) == *(arr + j))
      {
        for (int k = j; k < size - 1; k++)
        {
          *(arr + k) = *(arr + k + 1);
        }
        size--;
        j--;
      }
    }
  }
  printf("\nArray after removing duplicates : ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", *(arr + i));
  }
}

int main()
{
  int size;
  int *p;
  printf("Enter the size : ");
  scanf("%d", &size);
  p = (int *)malloc(size * sizeof(int));
  printf("enter the elements : ");
  for (int i = 0; i < size; i++)
  {
    scanf("%d", (p + i));
  }
  printf("Array : ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", *(p + i));
  }
  removeDuplicate(p, size);
}