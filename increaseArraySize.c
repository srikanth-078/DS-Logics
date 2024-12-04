#include<stdio.h>
#include<stdlib.h>
#define MAX 5

//passing values inserting into array.
    void insert(int value, int **arr, int *count, int *size){
        //condition to check array size reached to it't maximum or not.
        if(*count + 1 >= *size){
            *size = *size + MAX; // added estra maximum size to array.
            printf("Array size increased for more 5 Elements, Size is %d\n", *size);
            *arr = (int *)realloc(*arr, (*size) * sizeof(int)); // reallocating the estra max memory to array
            // *size = *size * 2; // Double the array size
            // int *newArr = (int *)malloc(*size * sizeof(int)); //Here we can use malloc function also.
            if(*arr == NULL){printf("allocation failed.\n");exit(1);}
        }
        (*count)++; //initially -1 adding 1 or incrementing it becomes 0(from zero to n number of indexes).
        (*arr)[*count] = value; //assigning value to arrays index place.
        printf("Inserted successfully at %d\n", *count);
    }

    void display(int *arr, int count){
        if(count == -1){ //if count value -1 array is empty.
            printf("Array is empty.\n");return;
        }
        printf("Array values are:\n");
        for(int i=0; i <= count; i++){
            printf("%d-%d ", i, arr[i]); //displays the index and value of array.
        }printf("\n");
    }

void main(){
    int size = 5, count = -1, ch, value;
    int *arr = (int *)malloc(size * sizeof(int)); //taking pointer array allocating memory to this array.

    while(1){
        printf("\n1. Insert.\n2. Display.\n3. exit.\nEnter Option: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter Element: ");
                scanf("%d", &value);
                insert(value, &arr, &count, &size);
                break;
            case 2:
                display(arr, count);
                break;
            case 3:
                exit(1); //exit the while loop or looping.
            default:
                printf("Enter correct option.");
        }
    }

    free(arr); //free the array memory.
}
