#include <stdio.h>
#include <stdlib.h>

struct tree* newnode(char );
void push(struct tree* );
struct tree* pop();
void inorder(struct tree* );
void preorder(struct tree* );
void postorder(struct tree* );


struct tree {
	char data;
	struct tree *left;
	struct tree *right;
};

struct tree* stack[30];
int top;
top = -1;
struct tree* newnode(char b){
	struct tree* temp;
	//your code
	temp=(struct tree*)malloc(sizeof(struct tree));
	temp->data=b;
	temp->left=NULL;
	temp->right=NULL;
	return(temp);
}

void push(struct tree* temp){
	//your code
	stack[++top]=temp;
}

struct tree* pop(){
	struct tree* temp;
	//your code
	temp=stack[top--];
	return(temp);
}

void inorder(struct tree* temp){

	if(temp!=NULL){
		//your code
		inorder(temp->left);
		printf("%c",temp->data);
		inorder(temp->right);
		//your code
	}
}

void preorder(struct tree* temp){

	if(temp!=NULL){		
		printf("%c",temp->data);
		preorder(temp->left);
		inorder(temp->right);
		//your code
	}
}

void postorder(struct tree* temp){

	if(temp!= NULL){
		//your code
		postorder(temp->left);
		postorder(temp->right);
		printf("%c",temp->data);
	}
}

void main(){
	char exp[20];
	struct tree* temp;
	int i;

	printf("\nEnter the postfix expression: ");
	//your code
	gets(exp);

	for(i=0; exp[i]!= NULL; i++){

		if(exp[i]=='-' || exp[i]=='/' || exp[i]=='*' || exp[i]=='+'){
			//your code	
			temp=newnode(exp[i]);
			temp->right=pop();
			temp->left=pop();
			push(temp);
		}
		else{
			//your code
			temp=newnode(exp[i]);
			push(temp);
		}
	}
	printf("\nInorder Traversal:\t");
	inorder(temp);
	//printf("\n");
	//your code
	printf("\nPreorder Traversal:\t");
	//your code
	preorder(temp);
	//printf("\n");
	printf("\nPostorder Traversal:\t");
	//your code
	postorder(temp);
	printf("\n");
        //your code
}
