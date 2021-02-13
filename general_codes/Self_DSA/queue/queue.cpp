// implementation of queue in c++
#include <iostream>
#define SIZE 5

using namespace std;
class Queue {
    private:
    int items[SIZE],front,rear;

    public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isFull() {
        if(front == 0 && rear == SIZE - 1){
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(front == -1){
            return true;
        }
        return false;
    }

    void enQueue(int element){
        if(isFull()){
            cout << "Queue is full" << endl;
        }
        else{
            if(front == -1)
              front = 0;
            rear++;
            items[rear] = element;
            cout << "Inserted " << element << endl;
        }
    }

    int dequeue(){
        int element;
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        else{
            element = items[front];
            if(front >= rear){
                front = rear = -1;
            }
            else{
                front++;
            }
            cout << "deleted " << element << endl;
            return element; 
        }
    }
    void display(){
        int i;
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
        }
        else{
            cout << "Front index " << front << endl;
            cout << "Items ";
            for(i=front; i <= rear; i++){
                cout << items[i] << " ";
            }
            cout << "\nRear index " << rear << endl;
        }
    }
};

int main() {
    Queue q;
    q.dequeue();

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    q.enQueue(6);

    q.display();

    q.dequeue();

    q.display();
}