#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key;
    int height;
    Node *left;
    Node *right;
};


int height(Node *N){
    if(N == NULL){
        return 0;
    }
    return N->height;

}

int getBalance(Node *N){
    if(N==NULL){
        return 0;
    }
    return height(N->left) - height(N->right);
}

Node* createNode(int keyV){
    Node* newNode = new Node();
    newNode->key = keyV;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;

}
Node *leftRotate(Node *x){
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = 1 + max( height(x->left), height(x->right) );
    y->height = 1 + max( height(y->left), height(y->right) );

    return y;
}

Node *rightRotate(Node *y){
    Node *x = y->left;
    Node *t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = 1 + max( height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;

}

Node* insert(Node* node, int key){
    if(node == NULL){
        return (createNode(key));
    }
    if(key < node->key){
        node->left = insert(node->left, key);
    }
    else if(key > node->key){
        node->right = insert(node->right, key);
    }
    else{
        return node;
    }
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if(balance > 1 && key < node->left->key){
        return rightRotate(node);
    }
    if(balance < -1 && key > node->right->key){
        leftRotate(node);
    }
    if(balance < 1 && key < node->left->key){
        node->left = leftRotate(node->right);
        return rightRotate(node);
    }
    if(balance <-1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return rightRotate(node);
    }
    return node;
}

void preorder(Node *root){
    if(root!=NULL){
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }

}

int main(){
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    cout << "preordal traversal = " << endl;
    preorder(root);
    return 0;
}