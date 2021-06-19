/*

*continuous tree are those whose difference between nodes is 1*

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
    newNode->data =  value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
bool checkContinuousTree(Node* root){
    if(root == NULL){
        return true;
    }
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    if(root->left == NULL){
        return (abs(root->data - root->right->data) == 1 && checkContinuousTree(root->right) );
    }
    if(root->right == NULL){
        return(abs(root->data - root->left->data) == 1 && checkContinuousTree(root->left));
    }
    return(
        abs(root->data - root->left->data) == 1 && abs(root->data - root->right->data) == 1 &&
        checkContinuousTree(root->left) && checkContinuousTree(root->right)
     );
}

int main(){
    Node* root;
    root = createNode(5);
    root->left = createNode(4);
    root->right = createNode(4);
    root->left->left = createNode(3);
    root->left->right = createNode(3);
    bool f = checkContinuousTree(root);
    (f)?(cout << "YES" << endl) : (cout << "NO" << endl);
}