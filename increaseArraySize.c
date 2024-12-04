#include<stdio.h>
#include<stdlib.h>
#define MAX 5
    int k = 0;
    void insert(int value, int **arr, int *count, int *size){

        if(*count + 1 >= *size){
            // printf("full\n");return;
            *size = *size + MAX;
            printf("Array size increased for more 5 Elements, Size is %d\n", *size);
            *arr = (int *)realloc(*arr, (*size) * sizeof(int));
            // *size = *size * 2;
            // int *newArr = (int *)malloc(*size * sizeof(int));
            if(*arr == NULL){printf("allocation failed.\n");exit(1);}
        }
        (*count)++;
        (*arr)[*count] = value;
        printf("Inserted successfully at %d\n", *count);
    }

    void display(int *arr, int count){
        if(count == -1){
            printf("Array is empty.\n");return;
        }
        printf("Array values are:\n");
        for(int i=0; i <= count; i++){
            printf("%d-%d ", i, arr[i]);
        }printf("\n");
    }

void main(){
    int size = 5, count = -1, ch, value;
    int *arr = (int *)malloc(size * sizeof(int));

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
                exit(1);
            default:
                printf("Enter correct option.");
        }
    }

    free(arr);
}