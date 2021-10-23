#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void push(Node** head, int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
void frontBackSplit(Node* source, Node** f, Node** r){
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
}
void mergeSort(Node** head){
    Node* headn = *head;
    Node* a;
    Node* b;
    if(headn == NULL || headn->next == NULL){
        return;
    }
    frontBackSplit(headn,&a,&b);
    mergeSort(&a);
    mergeSort(&b);

    *head = sortedMerge(a,b);
}
int main(){
    Node* res = NULL;
    Node* a = NULL;
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);
    MergeSort(&a);
    printList(&a);
    return 0;
}