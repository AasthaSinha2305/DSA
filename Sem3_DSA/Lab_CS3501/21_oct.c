//Write a program to implement stack using Linked List.

//ROLL NUMBER 1904155

#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*top,*top1,*temp;

int topelement();
void push(int data);
void pop();
void empty();
void display();
void destroy();
void stack_count();
void create();
 
int count = 0;
 
void main()
{
   // your code
   int choice, ele, ret;
    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Top");
    printf("\n 4 - Empty");
    printf("\n 5 - Exit");
    printf("\n 6 - Dipslay");
    printf("\n 7 - Stack Count");
    printf("\n 8 - Destroy stack");
    top = NULL;
    while(1){
        printf("\n Enter choice : ");
        scanf("%d",&choice);
        if(choice == 1){
            printf("Enter data : ");
            scanf("%d",&ele);
            push(ele);
        }
        else if(choice == 2){
            pop();
        }
        else if(choice == 3){
            ret = topelement();
            if(top == NULL){
                printf("No elements in stack");
            }
            else{
                printf("\n Top element : %d",ret);
            }
        }
        else if(choice == 4){
            empty();
        }
        else if(choice == 5){
            exit(1);
        }
        else if(choice == 6){
            display();
        }
        else if(choice == 7){
            stack_count();
        }
        else if(choice == 8){
            destroy();
        }
        else{
            printf(" Wrong choice, Please enter correct choice  ");
        }    
            
    }
}
 

/* Count stack elements */
void stack_count()
{
    //your code
    printf("\n No. of elements in stack : %d", count);
}
 
/* Push data into stack */
void push(int num)
{
    if(top == NULL){
        top = (struct node*)malloc(sizeof(struct node*));
        top->ptr = NULL;
        top->info = num;
    }
    else{
        temp = (struct node*)malloc(sizeof(struct node*));
        temp->ptr = top;
        temp->info = num;
        top = temp;
    }
    count++;
}
 
/* Display stack elements */
void display()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
    }
 
    while (top1 != NULL)
    {
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
}

 
/* Pop Operation on stack */
void pop()
{
    top1 = top;
    if(temp == NULL){
        printf("\nStack underflow\n");
    }
    else{
        top1 = top1->ptr;
        printf("\n Popped value : %d",top->info);
        free(top);
        top = top1;
        count--;
    }
   
}
 
/* Return top element */
int topelement()
{
    int top_element = top->info;
    return top_element;
}
 
/* Check if stack is empty or not */
void empty()
{
    if (top == NULL)
        printf("\n Stack is empty");
    else
        printf("\n Stack is not empty with %d elements", count);
}
 
/* Destroy entire stack */
void destroy()
{
    top1 = top;
 
    while (top1 != NULL)
    {
        top1 = top->ptr;
        free(top);
        top = top1;
        top1 = top1->ptr;
    }
    free(top1);
    top = NULL;
 
    printf("\n All stack elements destroyed");
    count = 0;
}
