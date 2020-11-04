#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev; 
};

struct Node *head;

void display_begin(){
    struct Node *temp;
    temp = head;
    if(head == NULL){
        printf("\nList is empty...\n");
    }
    else{
        printf("Element in list in forward direction...: ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }

}

void display_back(){
    if(head == NULL){
        printf("\nList is empty..\n");
    }
    else{
        printf("\nElement in list in backward direction...: ");
        struct Node *temp, *temp1;
        temp = head;
        while(temp!=NULL){
            temp1 = temp;
            temp = temp->next;
        }
        while(temp1!=NULL){
            printf("%d ",temp1->data);
            temp1 = temp1->prev;
        }
    }
}
void insert_after(struct Node *new_node){
    int ele;
    printf("\nAfter which element you want to insert: ");
    scanf("%d",&ele);
    if(head == NULL){
        printf("\nList is empty......\n");
    }
    else{
        struct Node *temp;
        temp = head;
        while(temp->data!=ele && temp!=NULL){
            temp = temp->next;
            if(temp== NULL){
                printf("\nElement not found...\n");
            }
        }
        //printf("IIIIIIIIIIIIIIIIIIIIIIIIIIII");
        if(temp!=NULL){
            new_node->next = temp->next;
            new_node->prev = temp;
            temp->next = new_node;
            if(new_node->next!=NULL){
                new_node->next->prev = new_node;
            }
            printf("\nElement inserted...\n");
        }
       // printf("IIIIIIIIIIIIIIIIIIIIIIIIIIII");
    }
}
void insert_end(struct Node *new_node){
    if(head == NULL){
        head = new_node;
    }
    else{
        struct Node *temp;
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}


int main(){
    int n,i,x;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    struct Node *a[n],*w;
    for(i=0;i<n;i++){
        a[i] = (struct Node*)malloc(sizeof(struct Node*));
        printf("Enter the element to add: ");
        scanf("%d",&x);
        a[i]->data = x;
        a[i]->next = NULL;
        a[i]->prev = NULL;
        insert_end(a[i]);
    }
    display_begin();
    display_back();
    printf("\nEnter the element to add: ");
    scanf("%d",&x);
    w = (struct Node*)malloc(sizeof(struct Node*));
    w->data = x;
    w->next = NULL;
    w->prev = NULL;
    insert_after(w);
    display_begin();
    display_back();
}