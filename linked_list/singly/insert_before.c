#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct node *next;
};
struct Node *head = NULL;

void createlist(struct Node *new_node){
	struct Node *temp;
	if(head == NULL){
		head = new_node;
	}
	else{
		temp = head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next = new_node;
	}
}
void insert_Before(struct Node *new_node){
	struct Node *temp;
	if(head == NULL){
		head = new_node;
	}
	else{
		temp = head;
		new_node->next = head;
		head = new_node;
	}
}

void display(){
	struct Node *temp;
	temp = head;
	if(temp == NULL){
		printf("List is empty");
	}
	else{
		printf("The list is : ");
		while(temp->next!=NULL){
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
}

int main(){
	int i,n,x;
	printf("Enter the number of element: ");
	scanf("%d",&n);
	struct Node *a[n];
	for(i=0;i<n;i++){
		a[i] = (struct Node*)malloc(sizeof(struct Node*));
		printf("Enter the element: ");
		scanf("%d",&x);
		a[i]->data=x;
		a[i]->next=NULL;
		createlist(a[i]);
	}
	display();
	printf("\nEnter the number you want to add in beginning: ");
	scanf("%d",&x);
	struct Node *w;
	w->data=x;
	w->next=NULL;
	insert_Before(w);
	display();
	return 0;
}