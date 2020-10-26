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
void delete_somewhere(){
    struct Node *temp,*prev;
    int ele;
    temp = head;
    printf("\nEnter the element you want to delete: ");
    scanf("%d",&ele);
    if(head == NULL){
        printf("\nList Empty...deletion not possible...\n");
    }
    else{
        
        prev = temp;
        while(temp!=head){
            if(temp->data==ele){
                if(temp == head){
                    printf("\nElement deleted\n");
                    head = temp->next;
                    free(temp);
                    break;
                }
                else{
                    printf("\nElement deleted\n");
                    prev->next = temp->next;
                    free(temp);
                    break;
                    

                }
            }
            else{
                prev=temp;
                temp = temp->next;
            }
        }
        if(temp == head){
            printf("\nElement not found...\n");
        }
    }
}
void display(){
    struct Node *temp;
    temp =  head;
    if(temp == NULL){
        printf("\nEmpty list");
    }
    else{
        printf("\nThe elements in list are: ");
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
    delete_somewhere();
    display();
    return 0;
}
