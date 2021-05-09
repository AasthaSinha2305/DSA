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
void deleteTheNode(Node* root,Node* toDelete){

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == toDelete){
            temp == NULL;
            delete toDelete;
            return;
        }
        if(temp->left){
            if(temp->left == toDelete){
                temp->left = NULL;
                delete toDelete;
                return;
            }
            else{
                q.push(temp->left);
            }
        }
        if(temp->right){
            if(temp->right==toDelete){
                temp->right = NULL;
                delete toDelete;
                return;
            }
            else{
                q.push(temp->right);
            }
        }
    }
}
Node* deletion(Node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        if(root->data==key){
            return NULL;
        }
        else{
            return root;
        }
    }
    queue<Node*> q;
    q.push(root);
    Node* temp;
    Node* keyNode = NULL;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->data==key){
            keyNode = temp;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    if(keyNode != NULL){
        int x = temp->data;
        deleteTheNode(root, temp);
        keyNode->data = x;
    }

    return root;
    

}
int main(){
    Node* root = createNode(11);
    root->left = createNode(12);
    root->right = createNode(13);
    root->left->left = createNode(14);
    root->left->right = createNode(15);
    inorder(root);
    cout << endl;
    root = deletion(root,12);
    inorder(root);

    return 0;
}