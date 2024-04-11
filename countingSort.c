#include <stdio.h>

void counting(int arr[], int size)
{
   int i;
   int countarray[10];
   int ans[10];
   int max;
   max = arr[0];
   for (i = 1; i < size; i++)
   {
      if (arr[i] > max)
      {
         max = arr[i];
      }
   }

   for (i = 0; i < max + 1; i++)
   {
      countarray[i] = 0;
   }
   for (i = 0; i < size; i++)
   {
      countarray[arr[i]]++;
   }
   for (i = 1; i < max + 1; i++)
   {
      countarray[i] += countarray[i - 1];
   }
   for (i = size - 1; i >= 0; i--)
   {
      ans[countarray[arr[i]] - 1] = arr[i];
      countarray[arr[i]]--;
   }
   for (i = 0; i < size; i++)
   {
      printf("%d ", ans[i]);
   }
}

int main()
{
   int i, size;
   int arr[10];

   printf("Enter the size of an array : ");
   scanf("%d", &size);
   arr[size];

   printf("Enter the elements : ");

   for (i = 0; i < size; i++)
   {
      scanf("%d", &arr[i]);
   }
   counting(arr, size);

   return 0;
}
