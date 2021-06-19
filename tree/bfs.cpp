/*
*using recursion*
*/

#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh >= rh){
        return (lh+1);
    }
    else{
        return rh+1;
    }
}
void printThisLevel(Node* root, int level){
    if(root == NULL){
        return;
    }
    if(level == 1){
        cout << root->data << " ";
    }
    printThisLevel(root->left, level-1);
    printThisLevel(root->right,level-1);
}
void printLevelOrder(Node* root){
    int h = height(root);
    for(int i = 1; i<=h; i++){
        printThisLevel(root, i);
    }
}
int main(){
    Node* root = createNode(11);
    root->left = createNode(12);
    root->right = createNode(13);
    root->left->left = createNode(14);
    root->left->right = createNode(15);
    printLevelOrder(root);

    return 0;
}

/*
*simply using a queue*
*/

// #include <bits/stdc++.h>
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