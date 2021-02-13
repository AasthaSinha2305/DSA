#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
};

void deleteNode(Node** head_ref, int ele){
    Node* temp = *head_ref;
    Node* prev = NULL;

    if(temp!=NULL && temp->data == ele){
        *head_ref = temp->next;
        delete temp;
        return;
    }
    while(temp!=NULL && temp->data!=ele){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    prev->next = temp->next;
    delete temp;
}
void printList(Node *n){
    cout << "Linked list is: ";
    while(n!=NULL){
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main(){
    int n, i, x;
    cout << "Enter he number of elements: ";
    cin >> n;
    Node *a[n];
    for(i=0;i<n;i++){
        a[i] = new Node();
    }
    for(i=0; i<n; i++){
        cout << "Enter the Element: ";
        cin >> a[i]->data;
        if(i!=n-1){
            a[i]->next = a[i+1];
        }
        else{
            a[i]->next = NULL;
        }
    }
    printList(a[0]);
    cout << "Enter the element to delete: ";
    cin >> x;
    deleteNode(&a[0],x);
    printList(a[0]);

}