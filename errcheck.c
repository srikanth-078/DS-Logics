#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node* head = NULL;

struct node* create(int data){
    struct node *nn = malloc(sizeof(struct node));
    if(nn == NULL){
        printf("Error to allocate memory.");
        exit(0);
    }
    nn->data = data;
    nn->next = NULL;
    return nn;
}

void insertBig(){
    int data;
    printf("Enter to insert:");
    scanf("%d",&data);
    struct node* nn = create(data);
    nn->next = head;
    head = nn;
    printf("inserted suc.%d\n",head->data);
}

void insertEnd(int data){
    struct node* nn = create(data);
    if (head == NULL) {
        head = nn;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nn;
    }
    printf("Successfully inserted at end.\n");
}

void display(){
    struct node* temp = head;
    printf("values are:\n");
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertNAfter(int key,int data){
    struct node *keyAfter = head,*nn = create(data),*p;
    while(keyAfter!=NULL && keyAfter->data!=key){
        keyAfter = keyAfter->next;
    }
    if(keyAfter==NULL){
        printf("Element not found.");
        return;
    }
    p = keyAfter;
    nn->next = p->next;
    keyAfter->next = nn;
    printf("sucsses.");
}

void insertNBefore(int key,int val){
    struct node *keyBefore = head,*nn = create(val),*p,*temp = NULL;
    while(keyBefore!=NULL && keyBefore->data != key){
        temp = keyBefore;
        keyBefore=keyBefore->next;
    }
    if(keyBefore == NULL){
        printf("Element is not found.");
        return;
    }
    if(temp == NULL){
        head = nn;
    }else{
        temp->next = nn;
    }
    nn->next = keyBefore;
    printf("sucsses.");
}

void deletelist(int delKey){
    struct node *del = head,*correct;
    while(del!=NULL && del->data!=delKey){
        correct = del;
        del = del->next;
    }
    if(del == NULL){
        printf("Element is not found.");
    }else{
    correct->next = del->next;
    printf("%d is successfully deleted.",del->data);
    free(del);
    }
}

void sortArray(int *arr,int n){
    for(int i = 0; i < n - 1 ; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void freeList(struct node *head) {
    struct node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void sortlist(){
    struct node *sort = head;
    int size = 0;
    while(sort!=NULL){
        sort = sort->next;
        size++;
    }
    if(size == 0){
        printf("List is empty.");
        return;
    }
    int arr[size];
    struct node *toArray = head;
    for(int i=0;i<size;i++){
        arr[i]=toArray->data;
        toArray = toArray->next;
    }
    sortArray(arr,size);

freeList(head);
head = NULL;
    for(int i=0;i<size;i++){
            struct node *nn = create(arr[i]);
        if(head == NULL){
            head = nn;
        }
        else{
            nn->next = head;
            head = nn;
        }
    }
    printf("successfuly sorted.");
}

///insert values at position.
void insertPos(int data,int pos){
    struct node *insPos = head, *nn = create(data),*curr;
    int i = 1;
    if(head == NULL) {printf("List is empty.");return;}
    while(insPos!=NULL && i!=pos){
        curr = insPos;
        insPos = insPos->next;
        i++;
    }
    if(insPos == NULL){
        printf("insertion is failed.\n%d is more than list size.",pos);
        return;
    }
    curr->next = nn;
    nn->next = insPos;
    printf("successfuly inserted %d at position %d.",data,pos);
}

void main(){
    int ch,key,data;
    do{
        printf("\n\nEnter options:\n1.insertBig.\n2.insertEnd.\n3.display\n4.insert a number after.\n5.insert a number before.\n6.delete\n7.sort list\n8.insert by postion.\n9.eixt\nenter:");
        scanf("%d",&ch);
        switch(ch){
            case 1:insertBig();break;
            case 2:
                printf("Enter a number for insert at End:");
                scanf("%d",&data);
                insertEnd(data);break;
            case 3:display();break;
            case 4:
                printf("Enter key:");
                scanf("%d",&key);
                printf("enter data to insert %d after: ",key);
                scanf("%d",&data);
                insertNAfter(key,data);
                break;
            case 5:
                printf("Enter key:");
                scanf("%d",&key);
                printf("enter data to insert %d after: ",key);
                scanf("%d",&data);
                insertNBefore(key,data);
                break;
            case 6:
                printf("Enter number to delete: ",data);
                scanf("%d",&data);
                deletelist(data);
                break;
            case 7:
                sortlist();
                break;
            case 8:
                printf("Enter position to insert: ");
                scanf("%d",&data);
                printf("Enter data to insert: ");
                scanf("%d",&key);
                insertPos(data,key);
                break;
            case 9:printf("Thakyou for using.");return;
            default:printf("Enter correct option.");
        }
    }while(1);
}