#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void create(struct Node *new_node){
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
void insert_End(struct Node *new_node){
    struct Node *temp;
    if(head == NULL){
        head = new_node;
    }
    else{
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
void display(){
    struct Node *temp = head;
    if(temp == NULL){
        printf("Empty list");
    }
    else{
        printf("The elements in list: ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp= temp->next;
        }
    }
}
int main(){
    int n,i,x;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    struct Node *a[n];
    for(i=0;i<n;i++){
        a[i] = (struct Node*)malloc(sizeof(struct Node*));
        printf("Enter element %d: ",i+1);
        scanf("%d",&x);
        a[i]->data = x;
        a[i]->next = NULL;
        create(a[i]);
    }
    display();
    struct Node *w;
    w = (struct Node*)malloc(sizeof(struct Node*));
    printf("\nEnter the element to add at the end: ");
    scanf("%d",&x);
    w->data = x;
    w->next=NULL;
    insert_End(w);
    display();
    return 0;
}