#include <stdio.h>
void sort(int a[], int low, int high)
{
  int piv;
  if (low < high)
  {
    piv = partition(a, low, high);
    sort(a, low, piv - 1);
    sort(a, piv + 1, high);
  }
}
int partition(int a[], int start, int end)
{
  int pivot = a[start], temp;
  int s = start;
  int e = end;
  while (s < e)
  {
    while (a[s] <= pivot && s < e)
    {
      s++;
    }
    while (a[e] > pivot)
    {
      e--;
    }

    if (s < e)
    {
      temp = a[s];
      a[s] = a[e];
      a[e] = temp;
    }
  }

  a[start] = a[e];
  a[e] = pivot;
  return e;
}
int main()
{
  int n, i, lb, ub;
  printf("\nEnter array size:");
  scanf("%d", &n);
  int a[n];
  printf("\nEnter array elements:");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printf("\nArray:\n");
  for (i = 0; i < n; i++)
    printf(" %d ", a[i]);
  lb = 0;
  ub = n - 1;
  sort(a, lb, ub);
  printf("\nSorted Array:\n");
  for (i = 0; i < n; i++)
    printf(" %d", a[i]);
}