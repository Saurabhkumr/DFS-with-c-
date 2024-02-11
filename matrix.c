#include <stdio.h>

void multiplication(int arr1[][10], int arr2[][10], int row1, int col1, int row2, int col2)
{

    int final[10][10];
    int i, j, k;
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            final[i][j] = 0;
            for (k = 0; k < row2; k++)
            {
                final[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    printf("Resultant matrix : \n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            printf("%d ", final[i][j]);
        }
        printf("\n");
    }
}

void addition(int arr1[][10], int arr2[][10], int row, int col)
{
    int sum[10][10];
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    printf("Resultant matrix : \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}
void subtraction(int arr1[][10], int arr2[][10], int row, int col)
{
    int sub[10][10];
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            sub[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
    printf("Resultant matrix : \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", sub[i][j]);
        }
        printf("\n");
    }
}
void inverse(int arr1[][10], int row, int col)
{
    int ans[10][10];
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            ans[i][j] = arr1[j][i];
        }
    }
    printf("Resultant matrix : \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int row1, col1, row2, col2, i, j, k;
    int opt;
    char continueChoice;
    int sum[10][10];
    int arr1[10][10];
    int arr2[10][10];

    printf("enter number of rows for 1st matrix :");
    scanf("%d", &row1);
    printf("enter number of columns for 1st matrix :");
    scanf("%d", &col1);

    printf("enter the elements of 1st matrix : ");

    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("1st matrix : \n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }

    printf("enter number of rows for 2nd matrix :");
    scanf("%d", &row2);
    printf("enter number of columns for 2nd matrix :");
    scanf("%d", &col2);

    printf("enter the elements of 2nd matrix : ");

    for (i = 0; i < row2; i++)
    {
        for (j = 0; j < col2; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }
    printf("2nd matrix : \n");
    for (i = 0; i < row2; i++)
    {
        for (j = 0; j < col2; j++)
        {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

    do
    {
        printf("-----------------Matrix Operation----------------");
        printf("\n 1. Multiplication");
        printf("\n 2. Addition");
        printf("\n 3. Subtraction");
        printf("\n 4. Inverse");
        printf("\n Choose the operation you want to perform : ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            // Multiplication

            if (col1 == row2)
            {
                multiplication(arr1, arr2, row1, col1, row2, col2);
            }
            else
            {

                printf("Wrong format !");
            }

            break;

        case 2:
            //  Addition
            addition(arr1, arr2, row1, col1);
            break;

        case 3:
            // Subtraction
            subtraction(arr1, arr2, row1, col1);
            break;

        case 4:
            // Inverse
            inverse(arr1, row1, col1);
            break;

        default:
            printf("Inalid Input !");

        }
        printf("Do you want to continue (y/n) : ");
        scanf(" %c", &continueChoice);

    } while(continueChoice == 'y');
    

        printf("Program Exit...");

        return 0;
}