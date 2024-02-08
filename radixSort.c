#include <stdio.h>
void radix(int arr[], int size, int pos)
{
    int i;
    int count[10];
    int output[size];

    for (i = 0; i < 10; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < size; i++)
    {
        count[(arr[i] / pos) % 10]++;
    }
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / pos) % 10] - 1] = arr[i];
        count[(arr[i] / pos) % 10]--;
    }
    for (i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int i, max;
    int arr[10];
    int size;
    printf("enter the size : ");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("array : ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    max = arr[0];
    for (i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    for (i = 1; max / i > 0; i = i * 10)
    {
        radix(arr, size, i);
    }
    printf("\nsorted array : ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}