#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value){
    Node* new_node = new Node();
    new_node->data = value;
    new_node->left = new_node->right = NULL;
    return new_node;
}
Node* insertNode(int value, Node* root){
    if(root == NULL){
        root = createNode(value);
        return root;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        else{
            temp->left = createNode(value);
            return root;
        }
        if(temp->right){
            q.push(temp->right);
        }
        else{
            temp->right = createNode(value);
            return root;
        }
    }
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    int arr[5] = {1,2,3,4,5};
    Node* root = new Node();
    root = NULL; //createNode(arr[0]);
    for(int i=0;i<5;i++){
        root = insertNode(arr[i], root);
    }
    inorder(root);
    return 0;
}
