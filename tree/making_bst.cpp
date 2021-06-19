#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
};

Node* creatNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node*  insertNode(Node* root, int keyValue){
    if(root == NULL){
        root = creatNode(keyValue);
        return root;
    }
    if(keyValue > root->data){
        root->right = insertNode(root->right, keyValue);
    }
    else{
        root->left = insertNode(root->left, keyValue);
    }
    return root;
}
Node* createBST(Node* root, int arr[], int n){
    for(int i=0;i<n;i++){
        root  = insertNode(root, arr[i]);
    }
    return root;
}
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right); 
}
int main(){
    Node* root = NULL;
    int arr[] = {50,30,20,40,70,60,80};
    int n = 7;
    root = createBST(root,arr,n);
    inorder(root);
    return 0;
}