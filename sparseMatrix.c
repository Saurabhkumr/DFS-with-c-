#include <stdio.h>

int main()
{
    int i,j,k, rows , columns , count;
    int array[10][10];
    int sparsematrix[10][10];

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &columns);

 

    array[rows][columns];

    // Input values into the array
    printf("Enter elements of the array:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            printf("Enter element at position (%d, %d): ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    // Display the entered 2D array

    printf("Entered 2D array:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
    count = 0;
    printf("checking for sparse...\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            if (array[i][j] != 0)
            {
                count++;
            }
        }
    }


    if (count <= ((rows * columns) / 2))
    {
        printf("Sparse Matrix....\n");
    }
    else
    {
        printf("Not a sparse matrix....\n");
    }

    // 3 triplet representation

    sparsematrix[3][count];

    // Making of new matrix
    k = 0;
    for (i = 0; i < rows; i++){
        for (j = 0; j < columns ; j++){
            if (array[i][j] != 0)
            {
                sparsematrix[0][k] = i;
                sparsematrix[1][k] = j;
                sparsematrix[2][k] = array[i][j];
                k++;
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < count; j++)
            printf("%d ", sparsematrix[i][j]);

        printf("\n");
    }


    return 0;
}