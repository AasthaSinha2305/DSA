#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void printList(Node* n){
    cout << "The linked list: ";
    while(n!=NULL){
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
/* appending at the end */
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

void push(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
void insertAfter(int element, int new_data, Node** head_ref){
    Node* prev_node = *head_ref;
    while(prev_node->data!= element && prev_node!=NULL){
        prev_node = prev_node->next;
    }
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;


}

int main(){
    int n, i, option, x, ele;
    cout << "Enter the no. of elements: ";
    cin >> n;
    Node* head =NULL;
    for(i=0; i<n; i++){
        cout << "Enter the element: ";
        cin >> x;
        append(&head,x);
        /*cin >> a[i]->data;
        if(i!=n-1){
            a[i]->next = a[i+1];
        }
        else{
            a[i]->next = NULL;
        }
        */
    }
    printList(head);

    while(1){
        cout << "\n1 : Append" << endl;
        cout << "2 : Push" << endl;
        cout << "3 : Insert After" << endl;
        cout << "4 : print List" << endl;
        cout << "5 : Exit" << endl;

        cout << "Enter the option: ";
        cin >> option;

        if(option == 1){
            cout << "Enter the data: ";
            cin >> x;
            append(&head, x);
            cout << "Element appended" << endl;
        }
        else if(option == 2){
            cout << "Enter the data: ";
            cin >> x;
            push(&head, x);
            cout << "Element pushed" << endl;
        }
        else if(option == 3){
            cout << "Enter the data: ";
            cin >> x;
            cout << "Enter after which element you want to insert: ";
            cin >> ele;
            insertAfter(ele, x, &head);
            cout << "Element inserted" << endl;
        }
        else if(option == 4){
            printList(head);
        }
        else if(option == 5){
            break;
        }
    }
    return 0;
}
