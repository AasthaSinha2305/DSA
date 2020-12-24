#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
};

void printList(Node* n){
    cout << "The linked list: " ;
    while(n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
}

int main(){
    int n,i;
    cout << "Enter the number of elemnts: ";
    cin >> n;
    Node* a[n];
    for(i=0; i<n ;i++){
        a[i] = new Node();
    }
    for(i=0; i<n; i++){
        cout << "Element element: ";
        cin >> a[i]->data;
        if(i!=n-1){
            a[i]->next = a[i+1];
        }
        else{
            a[i]->next = NULL;
        }
    }
    printList(a[0]);
    return 0;
}