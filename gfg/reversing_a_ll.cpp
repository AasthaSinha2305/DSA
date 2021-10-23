#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node* next;
	Node(int val){
		this->data = val;
		next = NULL;
	}
};

struct LinkedList{
	Node* head;
    LinkedList(){
        head = NULL;
    } 
    void reverse(){
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(current!=NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void print(){
        Node* temp = head;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->next; 
        }
        cout << endl;
    }
    void push(int data){
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;

        
    }
    
};



int main(){
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
    ll.print();
    ll.reverse();
    ll.print();
	return 0;
}