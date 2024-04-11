#include <stdio.h>

int main()
{
    int i, j, k, rows, columns, count;
    int array[10][10];
    int rowMatrix[10][10];
    int colMatrix[10][10];

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

    // row representation
    printf("Row representation....\n");
    rowMatrix[3][count];

    // Making of new matrix
    k = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            if (array[i][j] != 0)
            {
                rowMatrix[0][k] = i;
                rowMatrix[1][k] = j;
                rowMatrix[2][k] = array[i][j];
                k++;
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < count; j++)
            printf("%d ", rowMatrix[i][j]);

        printf("\n");
    }

    // Column representation

    printf("Column representation....\n");

    colMatrix[count][3];

    // Making of new matrix
    k = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            if (array[i][j] != 0)
            {
                colMatrix[k][0] = i;
                colMatrix[k][1] = j;
                colMatrix[k][2] = array[i][j];
                k++;
            }
        }
    }

    for (i = 0; i < count; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%d ", colMatrix[i][j]);

        printf("\n");
    }

    return 0;
}