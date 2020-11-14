//your code
//Write a program to implement expression tree using stack and its inorder, preorder, and postorder traversals.
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
struct tree* newnode(char b){
	struct tree* temp;
	//your code
}

void push(struct tree* temp){
	//your code
}

struct tree* pop(){
	struct tree* temp;
	//your code
}

void inorder(struct tree* temp){

	if(){
		//your code
		printf("%c",temp->data);
		//your code
	}
}

void preorder(struct tree* temp){

	if(){		
		printf("%c",temp->data);
		//your code
	}
}

void postorder(struct tree* temp){

	if(){
		//your code
		printf("%c",t->data);
	}
}

void main(){
	char exp[20];
	struct tree* temp;
	int i;

	printf("\nEnter the postfix expression: ");
	//your code

	for(){

		if(){
			//your code		}
		else{
			//your code
		}
	}
	printf("\nInorder Traversal:\t");
	//your code
	printf("\nPreorder Traversal:\t");
	//your code
	printf("\nPostorder Traversal:\t");
	//your code
	printf("\n");
        //your code
}
