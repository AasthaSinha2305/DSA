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

void delete_before(){
    int ele;
    printf("\nEnter the element before which you wnat to delete: ");
    scanf("%d",&ele);
    if(head == NULL){
        printf("\nDeletion not possible....\n");
    }
    else{
        
        struct Node *temp,*ptr;
        temp = head;
        
        if(head->next == head && head->prev == head){
            printf("\nDeletion not possible....\n");
        }
        else{
            if(head->data == ele){
                printf("\nDeletion not possible....\n");
            }
            else{
                temp = temp->next;
                while(temp->data!=ele && temp!=head){
                    temp = temp->next;
                }
                if(temp == head){
                    printf("\nElement not found....\n");
                }
                else{
                    ptr = temp->prev;
                    temp->prev = ptr->prev;
                    ptr->prev->next = temp;
                    if(ptr == head){
                        head = temp;
                    }
                    printf("\nElement deleted....\n");
                }
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
    delete_before();
    display_beg();
    display_end();
    return 0;
}