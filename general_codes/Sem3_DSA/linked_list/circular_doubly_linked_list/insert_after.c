#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head = NULL;

void display_beg(){
    if(head == NULL){
        printf("\nList is empty....\n");
    }
    else{
        struct Node *temp;
        temp = head;
        printf("\nThe elements in the list are(forward): ");

        if(head->next == head){
            printf("%d",temp->data);
        }
        else{
            while(temp->next!=head){
                printf("%d ",temp->data);
                temp= temp->next;
            }
            printf("%d ",temp->data);
        }
        
    }

}
void display_end(){
    if(head == NULL){
        printf("\nList is empty...\n");
    }
    else{
        printf("\nThe elements in the list are(backward): ");
        struct Node *temp;
        temp = head->prev;
        if(head->prev == head){
            printf("%d",temp->data);
        }
        else{
            while(temp!= head){
                printf("%d ",temp->data);
                temp = temp->prev;
            }
            printf("%d",temp->data);
        }
    }
}
void insert_end(struct Node *new_node){
    int x;
    printf("Enter the element to add: ");
    scanf("%d",&x);
    new_node->data = x;
    new_node->next = NULL;
    new_node->prev = NULL;
    if(head == NULL){
        head = new_node;
        new_node->next = head;
        new_node->prev = head;
    }
    else{
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
    }

}

void insert_after(struct Node *new_node){
    int ele;
    printf("\nEnter element after which you want to insert: ");
    scanf("%d",&ele);
    if(head == NULL){
        printf("\nInsertion not possible.....\n");
    }
    else if(head->data == ele && head ->next == head){
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
    }
    else{
        struct Node *temp;
        temp = head;
        if(head->data == ele){
            new_node->next = temp->next;
            new_node->prev = temp;
            temp->next = new_node;
            new_node->next->prev = new_node;
        }
        else{
            temp = head->next;
            while(temp->data!=ele && temp!=head){
                temp = temp->next;
            }
            if(temp == head){
                printf("\nElement not found...\n");
            }
            else{
                new_node->next = temp->next;
                new_node->prev = temp;
                temp->next = new_node;
                new_node->next->prev = new_node;
            }
        }
    }
    
}

int main(){
    int n, i;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    struct Node *a[n];
    for(i=0; i<n; i++){
        a[i] = (struct Node*)malloc(sizeof(struct Node*));
        insert_end(a[i]);
    }
    display_beg();
    display_end();
    struct Node *w;
    printf("\nEnter the element you want to insert: ");
    scanf("%d",&n);
    w = (struct Node*)malloc(sizeof(struct Node*));
    w->data = n;
    w->next = w->prev = NULL;
    insert_after(w);
    display_beg();
    display_end();
    return 0;
}