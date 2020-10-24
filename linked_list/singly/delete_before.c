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
void delete_begin(){
    struct Node *temp;
    temp = head;
    if(head == NULL){
        printf("Deletion not possible.....List is empty...\n");
    }
    else if(temp->next == NULL){
        printf("\nElement deleted at the beginning..\n");
        head = NULL;
        free(temp);
    }
    else{
        printf("\nElement deleted at the beginning..\n");
        head = temp->next;
        free(temp);
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
    delete_begin();
    display();
    return 0;
}
