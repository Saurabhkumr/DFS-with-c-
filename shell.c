#include <stdio.h>
#include <stdlib.h>

int n;
int arr[10];

void sort()
{
  for (int gap = n / 2; gap >= 1; gap = gap / 2)
  {
    for (int j = gap; j < n; j++)
    {
      for (int i = j - gap; i >= 0; i = i - gap)
      {
        if (arr[i + gap] > arr[i])
          break;
        else
        {
          int temp = arr[i + gap];
          arr[i + gap] = arr[i];
          arr[i] = temp;
        }
      }
    }
  }
}

int main()
{
  printf("Enter the size of array : ");
  scanf(" %d", &n);
  printf("Enter the data : ");
  for (int i = 0; i < n; i++)
  {
    scanf(" %d", &arr[i]);
  }
  printf("Sorted array : ");
  sort();
  for (int i = 0; i < n; i++)
  {
    printf(" %d", arr[i]);
  }
}