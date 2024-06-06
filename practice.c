#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int arr[])
{
  int i = 0;
  int j = 1;
  for (int i = 0; i < 6; i++)
  {

    for (int j = 0; j < 7 - i - 1; j++)
    {

      {
        if (arr[j] > arr[j + 1])
        {
          int temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }
  }
}
void insertion_sort(int arr[])
{
  for (int i = 1; i < 7; i++)
  {
    int temp = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > temp)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
}
void selection_sort(int arr[])
{
  for (int i = 0; i < 6; i++)
  {
    int min = i;
    for (int j = i + 1; j < 7; j++)
    {
      if (arr[j] < arr[min])
        min = j;
    }
    if (min != i)
    {
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  }
}
int main()
{
  int arr[] = {4, 2, 11, 2, 5, 56, 1};
  selection_sort(arr);
  for (int i = 0; i < 7; i++)
  {
    printf(" %d", arr[i]);
  }
}