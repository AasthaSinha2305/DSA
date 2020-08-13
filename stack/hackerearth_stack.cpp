#include <iostream>

using namespace std;
//declaring and initialising top as global variable
int top = -1;

//pushing values in stack
void push(int *stack, int item, int n){
    if(top == n-1)
        cout << "Stack is already full" << endl;
    else
    {
        top++;
        stack[top] = item;
    }
}
//checking if the stack is full or not
int isEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;     
}
//poping elements from the stack
void pop(){
    if(isEmpty())
        cout << "Stack is already empty" << endl;
    else{
        top--;
    }
}

//checking size anywhere either after push or pop
int size(){
    return (top + 1);
}
//checking value of to element in stack without poping it
int topElement(int *stack){
    return stack[top];
}
int main(){

    int stack[3];
    push(stack, 1 , 3);
    cout << "size " << size() << endl;
    push(stack, 2 , 3);
    cout << "size " << size() << endl;
    push(stack, 3 , 3);
    cout << "size " << size() << endl;
    push(stack, 4 , 3);
    cout << "size " << size() <<"\n"<< endl;

    for(int i=0;i<3;i++){
        pop();
        cout << "size " << size() << endl;
    }
    pop();
}