// Write a program to implement Queue data structure using linkedlist
// 1904155

#include<stdio.h>
#include<stdlib.h>
#define MAX 15

struct Node
{
   int data;
   struct Node *next;
};

struct Node *front = NULL,*rear = NULL;

void EnQueue(int);
void DeQueue();
void display();
int QueueSize();

void main()
{
    int ch=1,data;
    printf("\nQueue Implementation using Linked List\n\n");
    
    printf(" 1. Insertion in Queue\n");
    printf(" 2. Deletion From Queue\n");
    printf(" 3. Display Queue\n");
    printf(" 4. Number of elements in Queue\n");
    printf(" 5. Exit");
    while(ch)
    {
        printf("\n\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
         case 1 : if(QueueSize()>=MAX)
                  {
    	            printf(" Queue is full !");
    	            break;
	              }
		          printf(" Enter number to be put in Queue : ");
                  scanf("%d",&data);
                  EnQueue(data); break;
                  
         case 2 : DeQueue(); break;
                
         case 3 : display(); break;

         case 4 : if(QueueSize()==0)
                  printf(" Queue is Empty !");
                  else
                  printf(" Number of elements in Queue is %d ",QueueSize());
		          break;
         
         case 5 : exit(1);
                
         default : printf(" Invalid Choice !");
        }
    }
}

void EnQueue(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = NULL;

    if(front == NULL)
        front = rear = newNode;
    else
    {
        rear -> next = newNode;
        rear = newNode;
    }
    printf(" Data inserted in Queue !");
}

void DeQueue()
{
    if(front == NULL)
    printf(" Queue is Empty !");
    else
    {
        struct Node *temp = front;
        front = front -> next;
        printf(" %d Deleted from Queue !", temp->data);
        free(temp);
    }
}

void display()
{
    if(front == NULL)
    printf(" Queue is Empty !");
    else
    {
    	printf(" Queue Elements are : ");
        struct Node *temp = front;
        while(temp->next != NULL)
        {
            printf("%d ",temp->data);
            temp = temp -> next;
        }
        printf("%d ",temp->data);
   }
}

int QueueSize()
{
	int count=0;
    if(front==NULL)
    {
    	
    	return count;
	}
    else
    {
        struct Node *temp = front;
        while(temp->next != NULL)
        {
            count++;
            temp = temp -> next;
        }
    }
    return count+1;
}
