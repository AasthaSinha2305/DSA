//Write a program to implement Queue data structure using array.
//1904155

#include<stdio.h>
#include<stdlib.h>
#define max 15

int queue[max];
int front=0,rear=0;

main()
{
    int ch=1,i,j=1,x=max;
    printf("\nQueue Implementation using Array\n\n");
    
    printf(" 1. Insertion in Queue\n");
    printf(" 2. Deletion From Queue\n");
    printf(" 3. Display Queue\n");
    printf(" 4. Number of elements in Queue\n");
    printf(" 5. Exit\n");
    
    while(ch)
    {
        printf("\n Enter your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1 : if(rear==x)
                 printf(" Queue is Full !\n");
                 else
                 {
                    printf(" Enter number to be insert into Queue : ");
                    scanf("%d",&queue[rear++]);
                    printf(" Data inserted in Queue !\n");
                 }
                 break; 
            
        case 2 : if(front==rear)
                 printf(" Queue is empty !\n");
                 else
                 {
                    printf(" %d Deleted from Queue\n",queue[front++]);
                    x++;
                 }
                 break;
            
        case 3 : if(front==rear)
                 printf(" Queue is Empty !\n");
                 else
                {
                   printf(" Queue Elements are : ");
                   for(i=front; i<rear; i++)
                   printf("%d ",queue[i]);
                   printf("\n");
                }break;
        
		case 4 : if(front==rear)
                 printf(" Queue is Empty !\n"); 
				 else
				 printf(" Number of elements in Queue is %d\n",abs(front-rear));
				 break;
				        
        case 5 : exit(1);
        default : printf(" Invalid Choice !\n"); 
        }
    }
}
