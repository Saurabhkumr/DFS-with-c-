#include <stdio.h>

void mergeSort(int arr[], int s, int e);
void merge(int arr[], int s, int mid, int e);

int main()
{
  int n;
  int arr[10];
  printf("Enter the size of array : ");
  scanf("%d", &n);
  printf("Enter the elements : ");

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  mergeSort(arr, 0, n - 1);
  printf("Sorted Array : ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void mergeSort(int arr[], int s, int e)
{
  if (s < e)
  {
    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, mid, e);
  }
}

void merge(int arr[], int s, int mid, int e)
{

  int len = e - s + 1;
  int arr2[10];
  int i = s;
  int j = mid + 1;
  int k = 0;
  while (i <= mid && j <= e)
  {
    if (arr[i] <= arr[j])
    {
      arr2[k] = arr[i];
      i++;
    }
    else
    {
      arr2[k] = arr[j];
      j++;
    }
    k++;
  }
  while (i <= mid)
  {
    arr2[k] = arr[i];
    k++;
    i++;
  }
  while (j <= e)
  {
    arr2[k] = arr[j];
    k++;
    j++;
  }

  for (int l = 0; l < len; l++)
  {
    arr[s + l] = arr2[l];
  }
}
