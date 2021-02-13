#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int count = 0;

struct stack {
    int items[SIZE];
    int top;
};
typedef struct stack st;

void createEmptyStack(st *s){
    s->top = -1;
}
int isfull(st *s){
    if(s->top == SIZE -1)
      return 1;
    else 
      return 0;
}

int isempty(st *s){
    if(s->top == -1)
      return 1;
    else
      return 0;
}
void push(st *s, int newitem){
    if(isfull(s)){
        printf("\nSTACK FULL\n");
    }
    else{
        s->top++;
        s->items[s->top] = newitem;
    }
    count++;
}

void pop(st *s){
    if(isempty(s)){
        printf("\nSTACK EMPTY\n");
    }
    else{
        printf("\nItem popped = %d\n",s->items[s->top]);
        s->top--;
    }
    count--;
}

void printStack(st *s){
    printf("Stack: ");
    for(int i=0;i<count;i++){
        printf("%d ",s->items[i]);
    }
}


int main(){
    int ch;
    st *s = (st *)malloc(sizeof(st));
    createEmptyStack(s);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printStack(s);
    pop(s);
    printf("\nAfter popping out\n");
    printStack(s);

}