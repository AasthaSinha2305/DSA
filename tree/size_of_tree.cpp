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

int sizeCalc1(Node* root){
    if(root == NULL){
        return 0;
    }
    return ( sizeCalc1(root->left) + 1 + sizeCalc1(root->right) );
}

int sizeCalc2(Node* root){
    if(root == NULL){
        return 0;
    }
    queue<Node*> q;
    q.push(root);
    int cnt = 1;
    while(!q.empty()){
        Node* temp = q.front();

        if(temp->left){
            q.push(temp->left);
            cnt++;
        }
        if(temp->right){
            q.push(temp->right);
            cnt++;
        }
        q.pop();
    }
    return cnt;
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);

}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = makeTree(root, arr, n, 0);
    //using recursion
    int d1 = sizeCalc1(root);
    //using iterative method
    int d2 = sizeCalc2(root);
    cout << d1 << " " << d2 << endl;
    inOrder(root);
    return 0;
}