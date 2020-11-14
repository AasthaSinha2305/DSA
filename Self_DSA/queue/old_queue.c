//implementation in c
#include <stdio.h>
#define SIZE 5

void enqueue(int);
void dequeue();
void display();

int items[SIZE], front = -1, rear = -1;
int main(){
    //dequeue is not possible in an empty queue
    dequeue();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    //6th element will  not be added cause queue is full
    enqueue(6);
    display();

    //dequeue will remove the first element
    dequeue();
    //display the 4 left elements
    display();
    return 0;
}

void enqueue(int value){
    if (rear == SIZE -1)
      printf("\nqueue is full\n");
    else {
      if (front == -1)
        front = 0;
      rear++;
      items[rear] = value;
      printf("\nInserted = %d\n",value);
    }
}

void dequeue(){
    if(front == -1)
      printf("\nqueue is empty\n");
    else{
        printf("\nDeleted = %d\n",items[front]);
        front++;
        if (front > rear)
          front = rear = -1;
    }
}

void display(){
    if(rear == -1)
      printf("\nqueue is empty\n");
    else {
        int i;
        printf("\nqueue elements are\n");
        for(i=front; i<=rear; i++)
          printf("%d ",items[i]);
    }
    printf("\n");
}