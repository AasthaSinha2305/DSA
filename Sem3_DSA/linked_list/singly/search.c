#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert_End(struct Node *new_node){
    
    struct Node *temp;
    
    if(head==NULL){
        head = new_node;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
void search(){
    int ele;
    printf("\nEnter the number to search: ");
    scanf("%d",&ele);
    struct Node *temp;
    temp = head;
    if(head == NULL){
        printf("\nList is empty...\n");
    }
    else{
        while(temp!=NULL){
            if(temp->data == ele){
                printf("\nElement found\n");
                break;
            }
            temp = temp->next;
        }
        if(temp == NULL){
            printf("\nElement not found\n");
        }
    }
}
void display(){
    struct Node *temp;
    temp =  head;
    if(temp == NULL){
        printf("Empty list");
    }
    else{
        printf("The elements in list are: ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp= temp->next;
        }
    }
}
int main(){
    int n,i,x;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    struct Node *a[n];

    for(i=0;i<n;i++){
        a[i] = (struct Node*)malloc(sizeof(struct Node*));
        printf("Enter element : ");
        scanf("%d",&x);
        a[i]->data = x;
        a[i]->next = NULL;
        insert_End(a[i]);
    }
    display();
    search();
    return 0;
}
