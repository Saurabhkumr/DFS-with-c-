#include <stdio.h>

int main(int argc, char const *argv[])
{
    int size;
    int i;
    int flag = 0;
    int pos;
    int num;
    int add;
    int choice;
    char continueChoice;

    printf("Enter the size of an array : ");
    scanf("%d", &size);
    int arr[size];

    printf("Enter the elements : ");

    for (int i = 0; i < size - 1; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {

        printf("\n");
        printf("1. Traverse the array...\n");
        printf("2. Delete an element from the array...\n");
        printf("3. Add an element the array...\n");
        printf("4. Search any element using Linear Search...\n");
        printf("5. Search any element using Binary Search...\n");
        printf("\nChoose the above option to perform any operation : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            // Traversing the array

            printf("Array : ");

            for (i = 0; i < size - 1; i++)
            {
                printf("%d,", arr[i]);
            }
            printf("%d\n", arr[i]);

            break;

        case 2:

            // Add an element

            printf("Enter the element you want to add : ");
            scanf("%d", &add);
            printf("Enter the position : ");
            scanf("%d", &pos);

            for (i = size; i >= pos; i--)
            {

                arr[i] = arr[i - 1];
            }
            arr[pos - 1] = add;

            printf("Array after adding an element : ");
            for (i = 0; i < size - 1; i++)
            {
                printf("%d,", arr[i]);
            }
            printf("%d\n", arr[i]);

            break;


        case 3:

            // Deleting an element from array using index

            printf("Enter the position of an element you want to delete : ");
            scanf("%d", &pos);

            if (pos > size)
            {
                printf("Index out of bound \n");
            }
            else
            {

                for (i = pos - 1; i < size - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }

                size--;
                printf("Array after deleting the element : ");

                for (i = 0; i < size - 1; i++)
                {
                    printf("%d,", arr[i]);
                }
                printf("%d\n", arr[i]);
            }
            break;

        case 4:

            // Linear Search

            printf("Enter the element you want to search : ");
            scanf("%d", &num);
            for (i = 0; i < size; i++)
            {

                if (num == arr[i])
                {
                    printf("Entered element is at index : %d\n", i);
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                printf("Entered element is not present is array....\n");
            }

            break;

        case 5:

          printf("Enter the element you want to search : ");
          scanf("%d",&num);
          bubble_sort(num,0,size);
          printf("Entered element is at index : %d\n", binary_search(arr,num));
        default:
            printf("Wrong choice ! (Choose from above) \n");
        }

        printf("Do you want to continue (y/n) : ");
        scanf(" %c", &continueChoice);

    } while (continueChoice == 'y');

    printf("Program Exit...");

    return 0;
}

int binary_search(int arr[],int target){
   int start = 0;
   int mid;
   int end = sizeof(arr);
   while(start<=end){
    mid=start+(end-start)/2;

    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]>target){
        end=mid-1;
    }
    else if(arr[mid]<target){
        start = mid+1;
    }
    return -1;

   }
}
