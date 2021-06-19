#include <bits/stdc++.h>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* left;
//     Node* right;
// };
// Node* createNode(int value){
//     Node* newNode = new Node();
//     newNode->data = value;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }
// void printLevelOrder(Node* root){
//     if(root==NULL){
//         return;
//     }
//     queue<Node*> q;
//     q.push(root);
//     while(!q.empty()){
//         Node* temp = q.front();
//         cout << temp->data << " ";
//         q.pop();
//         if(temp->left){
//             q.push(temp->left);
//         }
//         if(temp->right){
//             q.push(temp->right);
//         }
//     }
// }
// int main(){
//     Node* root = createNode(11);
//     root->left = createNode(12);
//     root->right = createNode(13);
//     root->left->left = createNode(14);
//     root->left->right = createNode(15);
//     printLevelOrder(root);

//     return 0;
// }