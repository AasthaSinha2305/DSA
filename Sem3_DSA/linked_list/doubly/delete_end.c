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
void delete_end(){
    struct Node *temp;
    temp = head;
    if(head == NULL){
        printf("\nlist is empty...\n");
    }
    else{
        if(head->next == NULL){
            head = NULL;
            printf("\nElement deleted...\n");
        }
        else{
            while(temp->next !=NULL){
                temp = temp->next;
            }
            temp->prev->next = NULL;
            free(temp);
        }
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
    delete_end();
    display_begin();
    display_back();
}