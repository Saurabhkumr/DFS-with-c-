#include <stdio.h>

// Binary Search using iteration

int binary_search(int arr[], int target, int size)
{
    int start = 0;
    int mid;
    int end = size;
    while (start <= end)
    {
        mid = (start + end) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
    }
    return -1;
}

// Binary Search using recursion

int binary_search_recursion(int arr[], int target, int start, int end)
{
    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        binary_search_recursion(arr, target, start, mid - 1);
    }
    else if (arr[mid] < target)
    {
        binary_search_recursion(arr, target, mid + 1, end);
    }
}

// Bubble sort

void bubble_sort(int arr[], int size)
{

    while (size > 1)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        size--;
    }
}

// Insertion sort

void insertion_sort(int arr[], int size)
{
    int i, j, temp;
    for (i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main(int argc, char const *argv[])
{
    int size;
    int len;
    int i;
    int add;
    int pos;
    int largest;
    int Second;

    int count = 0;

    int target;

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
        printf("2. Add an element the array...\n");
        printf("3. Delete an element from the array...\n");
        printf("4. Search any element using Linear Search...\n");
        printf("5. Bubble Sort...\n");
        printf("6. Insertion Sort...\n");
        printf("7. Search any element using Binary Search (Iterative method)...\n");
        printf("8. Search any element using Binary Search (Recursion method)...\n");
        printf("9. Get the second largest element...\n");

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

            len = size;
            printf("Enter the position of an element you want to delete : ");
            scanf("%d", &pos);

            if (pos > len)
            {
                printf("Index out of bound \n");
            }
            else
            {

                for (i = pos - 1; i < len - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }

                len--;
                printf("Array after deleting the element : ");

                for (i = 0; i < len - 1; i++)
                {
                    printf("%d,", arr[i]);
                }
                printf("%d\n", arr[i]);
            }
            break;

        case 4:

            // Linear Search

            printf("Enter the element you want to search : ");
            scanf("%d", &target);
            for (i = 0; i < size; i++)
            {

                if (target == arr[i])
                {
                    printf("Entered element is at index : %d\n", i);
                    count++;
                }
            }

            if (count == 0)
            {
                printf("Entered element is not present is array....\n");
            }
            else
                printf("%d occurs is present %d times.\n", target, count);

            break;

        case 5:

            // Bubble sort

            bubble_sort(arr, size);

            printf("Array after sorting : ");
            for (i = 0; i < size - 1; i++)
            {
                printf("%d,", arr[i]);
            }
            printf("%d\n", arr[i]);
            break;

        case 6:

            // insertion sort

            insertion_sort(arr, size);

            printf("Array after sorting : ");
            for (i = 0; i < size - 1; i++)
            {
                printf("%d,", arr[i]);
            }
            printf("%d\n", arr[i]);
            break;

        case 7:
            // Binary search using iteration

            printf("Enter the element you want to search : ");
            scanf("%d", &target);
            bubble_sort(arr, size);
            printf("Entered element is at index : %d\n", binary_search(arr, target, size));
            break;

        case 8:
            // Binary search using recursion

            printf("Enter the element you want to search : ");
            scanf("%d", &target);
            bubble_sort(arr, size);
            printf("Entered element is at index : %d\n", binary_search_recursion(arr, target, 0, size));
            break;

        case 9:

            // Find Second

            largest = 0;
            Second = 0;

            for (i = 1; i < size; i++)
            {
                if (arr[i] > arr[largest])
                {
                    largest = i;
                }
            }
            for (i = 1; i < size; i++)
            {
                if (i != largest && arr[i] > arr[Second])
                {
                    Second = i;
                }
            }
            printf("Second largest element : %d\n", arr[Second]);
            break;

        default:
            printf("Wrong choice ! (Choose from above) \n");
        }

        printf("Do you want to continue (y/n) : ");
        scanf(" %c", &continueChoice);

    } while (continueChoice == 'y');

    printf("Program Exit...");

    return 0;
}
