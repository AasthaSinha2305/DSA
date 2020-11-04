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
void delete_after(){
    struct Node *temp,*prev;
    temp = head;
    prev = head;
    int ele;
    printf("\nEnter after which element you want to delete: \n");
    scanf("%d",&ele);
    if(head == NULL){
        printf("\nList empty..........\n");
    }
    else if(head ->next == NULL){
        printf("\nOnly one element in the list....Deletion not possible....\n");
    }
    else{
        temp = prev->next;
        while(prev->data!=ele && temp!=NULL){
            prev = prev->next;
            temp = prev->next;
        }
        if(temp!=NULL){
            prev->next = temp->next;
            printf("\nElement deleted...\n");
        }
        else{
            printf("\nElement not found......deletion not possible\n");
        }
    }
}
void display(){
    struct Node *temp;
    temp =  head;
    if(temp == NULL){
        printf("\nEmpty list");
    }
    else{
        printf("\nThe elements in list are: ");
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
    delete_after();
    display();
    return 0;
}
