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
    newNode->left = newNode->right=NULL;
    return newNode;
}
Node* makeTree(Node* root, int arr[], int n , int index){
    if(index>=n){
        return root;
    }
    Node* temp = createNode(arr[index]);
    root = temp;
    root->left = makeTree(root->left, arr, n, 2*index+1);
    root->right = makeTree(root->right, arr, n, 2* index+2);

}

int sizeCalc(Node* root){
    if(root == NULL){
        return 0;
    }
    return ( sizeCalc(root->left) + 1 + sizeCalc(root->right) );
}

void levelOrder(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }

}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = makeTree(root, arr, n, 0);
    int d = sizeCalc(root);
    cout << d << endl;
    levelOrder(root);
    return 0;
}