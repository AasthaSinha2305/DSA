#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void deletePosition(Node** head_ref, int position){
    int i;
    if(*head_ref == NULL){
        return;
    }
    Node* temp = *head_ref;
    if(position == 0){
        *head_ref = temp->next;
        delete temp;
        return;
    }
    for(i=0; temp!=NULL && i<position-1; i++){
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL){
        return;
    }
    Node* temp2 = temp->next->next;
    delete temp->next;

    temp->next = temp2;
}
void append(Node** head_ref, int new_data){
    Node* new_node = new Node();
    Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
}

void printList(Node* n){
    cout << "The linked List: ";
    while(n!=NULL){
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
int main()
{
    int n, x, i, pos;
    cout << "Enter the number of elements: ";  
    cin >> n;
    Node* head = NULL;
    for(i=0;i<n;i++){
        cout << "Enter the element: ";
        cin >> x;
        append(&head, x);
    }
    printList(head);
    cout << "Enter the index to delete: ";
    cin >> pos;
    deletePosition(&head, pos);
    printList(head);
    return 0;
}