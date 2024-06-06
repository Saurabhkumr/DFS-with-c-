#include <stdio.h>
void sort(int arr[], int low, int high);
int main()
{
  int size;
  // int arr[10];
  // printf("Enter the size of array : ");
  // scanf(" %d", &size);
  // printf("Enter the element of array : ");
  // for (int i = 0; i < size; i++)
  // {
  //   scanf(" %d", &arr[i]);
  // }
  int arr[9] = {19, 17, 15, 12, 16, 18, 4, 11, 13};
  sort(arr, 0, 9);
  printf("Sorted array : ");
  for (int i = 0; i < 9; i++)
  {
    printf(" %d", arr[i]);
  }
}

void sort(int arr[], int low, int high)
{
  if (low > high)
    return;
  int s = low;
  int e = high;
  int mid = s + (e - s) / 2;
  int pivot = arr[mid];
  while (s <= e)
  {
    while (arr[s] < pivot)
    {
      s++;
    }
    while (arr[e] > pivot)
    {
      e--;
    }
    if (s <= e)
    {
      int temp = arr[s];
      arr[s] = arr[e];
      arr[e] = temp;
      s++;
      e--;
    }
  }
  sort(arr, low, e);
  sort(arr, s, high);
}