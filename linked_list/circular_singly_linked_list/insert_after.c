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

void insert_after(struct Node *new_node){
    struct Node *temp,*temp1;
    int ele;
    printf("Enter value of element after which you want to add the element: ");
    scanf("%d",&ele);
    temp =  head;
    if(head == NULL){
        printf("\nList is empty...Insertion not possible...\n");
    }
    else{
        if(temp == head && temp->data == ele){
            new_node->next = temp->next;
            temp->next = new_node;
            printf("\nElement Inserted....\n");

        }
        else{
            temp = temp->next;
            while(temp->data != ele && temp!=head){
                temp = temp->next;
            }
            if(temp != head){
                new_node->next = temp->next;
                temp->next = new_node;
                printf("\nElement Inserted\n");
            }
            else{
                printf("\nElement not found\n");
            }
        }
       
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
    printf("\nEnter value to add: ");
    scanf("%d",&x);
    w->data = x;
    w->next = NULL;
    insert_after(w);
    display();
    return 0;
}