#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    struct node *prev;
    int n;
    struct node *next;
}*h,*temp,*temp1,*temp2,*temp4;
 
void insert1();
void insert2();
void insert3();
void traversebeg();
void traverseend(int);
void delete();
 
int count = 0;
 
void main()
{
    int ch;
 
    h = NULL;
    temp = temp1 = NULL;
 
    printf("\n 1 - Insert at beginning");
    printf("\n 2 - Insert at end");
    printf("\n 3 - Insert at position i");
    printf("\n 4 - Delete at i");
    printf("\n 5 - Display from beginning");
    printf("\n 6 - Display from end");
    printf("\n 7 - Exit");
 
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        //your code
                
            temp2 = h;
            if (temp2 == NULL)
                printf("\n Error : List empty to display ");
            else
            {
                printf("\n Reverse order of linked list is : ");
                traverseend(temp2->n);
            }
            break;

    }
}
 
/* TO create an empty node */
void create()
{
    int data;
 
    printf("\n Enter value to node : ");
    scanf("%d", &data);
    //your code
}
 
/*  TO insert at beginning */
void insert1()
{
//your code
}
 
/* To insert at end */
void insert2()
{
//your code
}
 
/* To insert at any position */
void insert3()
{
    int pos, i = 2;
 
    printf("\n Enter position to be inserted : ");
    scanf("%d", &pos);
    //your code

}
 
/* To delete an element */
void delete()
{
    int i = 1, pos;
 
    printf("\n Enter position to be deleted : ");
    scanf("%d", &pos);
   //your code
   printf("\n Node deleted");
   //your code lines
}
 
/* Traverse from beginning */
void traversebeg()
{
    //your code
    printf("\n Linked list elements from begining : ");
    //your code
}
 
/* To traverse from end recursively */
void traverseend(int i)
{
//your code
}
