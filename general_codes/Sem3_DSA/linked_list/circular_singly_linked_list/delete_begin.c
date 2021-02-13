#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert_End(struct Node *new_node){
    
    struct Node *temp;
    
    if(head==NULL){
        head = new_node;
        new_node->next = new_node;
    }
    else{
        temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }
}

void delete_begin(){
    struct Node *temp;
    temp = head;
    if(head == NULL){
        printf("\nThe list is empty...Deletion not possible\n");
    }
    else{
        printf("\nfirst element deleted...\n");
        while(temp->next != head){
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
        
    }
}

void display(){
    struct Node *temp;
    temp = head;
    if(head == NULL){
        printf("\nThe list is empty....\n");
    }
    else{
        printf("\nThe list of elements is....\n");
        while(temp->next!=head){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d",temp->data);
    }
}

int main(){
    int i,n,x;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    struct Node *a[n],*w;
    w = (struct Node*)malloc(sizeof(struct Node*));
    for(i=0;i<n;i++){
        a[i] = (struct Node*)malloc(sizeof(struct Node*));
        printf("Enter element: ");
        scanf("%d",&x);
        a[i]->data = x;
        a[i]->next = NULL;
        insert_End(a[i]);
    }
    display();
    delete_begin();
    display();
    return 0;
}