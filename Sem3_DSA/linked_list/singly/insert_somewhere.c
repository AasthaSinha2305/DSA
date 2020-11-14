#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void Insert_End(struct Node *new_node){
    struct Node *temp;
    temp = head;
    if(head == NULL){
        head = new_node;
    }
    else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new_node;
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
void insert_somewhere(struct Node *new_node){
    struct Node *temp;
    temp = head;
    int ele;
    printf("Enter after which element to insert: ");
    scanf("%d",&ele);
    if(head == NULL){
        printf("list empty insertion not pssible...");
    }
    else{
        while(temp->data!=ele && temp!=NULL){
            temp = temp->next;
        }
        if(temp!=NULL){
            new_node->next = temp->next;
            temp->next = new_node;
        }
        else{
            printf("Element not found...");
        }
    }
}
int main(){
    int i,n,x;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    struct Node *a[n];
    struct Node *w;
    for(i=0;i<n;i++){
        printf("Enter the element: ");
        scanf("%d",&x);
        a[i] = (struct Node*)malloc(sizeof(struct Node*));
        a[i]->data = x;
        a[i]->next = NULL;
        Insert_End(a[i]);

    }
    display();
    printf("\nEnter the element to insert: ");
    scanf("%d",&x);
    
    w = (struct Node*)malloc(sizeof(struct Node*));
    w->data = x;
    w->next = NULL;
    insert_somewhere(w);
    display();
    return 0;
}