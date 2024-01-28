#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int size;
    int i;
    bool flag = true;
    int pos;
    int num;
    int add;


    printf("Enter the size of an array : ");
    scanf("%d", &size);
    int arr[size];

    printf("Enter the elements : ");

    for (int i = 0; i < size-1; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Traversing the array

    printf("Array : ");


    for (i=0; i < size - 1; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("%d\n", arr[i]);

    // Deleting an element from array using index

    // printf("Enter the position of an element you want to delete : ");
    // scanf("%d", &pos);

    // if(pos>size){
    //     printf("Index out of bound");
    // }
    // else{

    // for (i = pos - 1; i < size - 1; i++)
    // {
    //     arr[i] = arr[i + 1];
    // }

    // size--;
    // printf("Array after deleting the element : ");

    // for (i = 0; i < size - 1; i++)
    // {
    //     printf("%d,", arr[i]);
    // }
    // printf("%d\n", arr[i]);

    // }



    // Linear Search

    // printf("Enter the element you want to search : ");
    // scanf("%d",&num);
    // for( i =0 ; i<size ;i++){

    //     if(num==arr[i]){
    //         printf("Entered element is at index : %d",i);
    //         flag=false;
    //         break;
    //     }

    // }

    // if(flag)
    // {
    //     printf("Entered element is not present is array....");
    // }
    

    // Add an element 

    printf("Enter the element you want to add : ");
    scanf("%d",&add);
    printf("Enter the position : ");
    scanf("%d",&pos);

    for( i = size ; i >= pos ;i--){

        arr[i]=arr[i-1];

    }
        arr[pos-1]=add;


    printf("Array after adding an element : ");
     for (i=0; i < size - 1; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("%d\n", arr[i]);
    



    

    return 0;
}
