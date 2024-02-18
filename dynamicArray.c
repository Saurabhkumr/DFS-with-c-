#include <stdlib.h>
#include <stdio.h>

int main()
{

    int size;
    int sum = 0;
    int *p;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    p = (int *)malloc(size * sizeof(int));
    // p=(int*)calloc(size,sizeof(int));
    printf("Enter the elements : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", (p + i));
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(p + i));
    }

    for (int i = 0; i < size; i++)
    {
        sum += *(p + i);
    }
    printf("\nSum of element of the array : %d", sum);
}