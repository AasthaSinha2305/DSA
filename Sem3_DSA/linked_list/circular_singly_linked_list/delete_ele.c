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

void delete_ele(){
    struct Node *prev, *temp,*temp1;
    int ele;
    printf("\nEnter element which you want to delete: ");
    scanf("%d",&ele);
    if(head == NULL){
        printf("\nList is empty....Deletion not possible.....\n");
    }
    else{
        if(head->data == ele && head->next == head ){
            head = NULL;
            printf("\nElement deleted...\n");
        }
        else{
            temp1 = head;
            temp = head;
            prev = head;
            temp = temp->next;
            if(head->data == ele){
                while(temp1->next!=head){
                    temp1 = temp1->next;
                }
                head = prev->next;
                temp1->next = head;
                printf("\nElement deleted...............\n");
            }
            else{
                while(temp->data!=ele && temp!=head){
                    prev = prev->next;
                    temp = temp->next;
                }
                if(temp == head){
                    printf("\nElement not found\n");
                }
                else if(temp!=NULL){
                    prev->next = temp->next;
                    free(temp);
                    printf("\nElement deleted\n");
                }
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
        printf("%d ",temp->data);
    }
}

int main(){
    int i,n,x;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    struct Node *a[n];
    for(i=0;i<n;i++){
        a[i] = (struct Node*)malloc(sizeof(struct Node*));
        printf("Enter element: ");
        scanf("%d",&x);
        a[i]->data = x;
        a[i]->next = NULL;
        insert_End(a[i]);
    }
    display();
    delete_ele();
    display();
    return 0;
}