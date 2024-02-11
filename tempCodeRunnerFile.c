
void multiplication(int arr1[][10] , int arr2[][10], int row1 , int col1 , int row2 ,int col2){
 
    int sum[10][10];
    int i , j ,k ;
        for (i = 0; i < row1; i++)
        {
            for (j = 0; j < col2; j++)
            {
                sum[i][j] = 0;
                for (k = 0; k < row2; k++)
                {
                    sum[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        printf("Resultant matrix : \n");
        for (i = 0; i < row1; i++)
        {
            for (j = 0; j < col2; j++)
            {
                printf("%d ", sum[i][j]);
            }
            printf("\n");
        }

}