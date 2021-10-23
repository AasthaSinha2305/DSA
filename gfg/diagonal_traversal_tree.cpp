#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int val){
    Node* newNode = new Node();
    newNode->left = newNode->right = NULL;
    newNode->data = val;
    return newNode;
}
void fillmap(Node* root, int d , map<int, vector<int> > &mp){
    if(!root){
        return;
    }
    mp[d].push_back(root->data);
    fillmap(root->left, d+1, mp);
    fillmap(root->right, d, mp);
}
void printDiagonally(Node* root){
    map<int, vector<int> > mp;
    fillmap(root, 0, mp);
    for(auto x: mp){
        for(auto y : x.second){
            cout << y << " ";
        }
    }
}

void queueMethod1(Node* root){
    vector<int> ans;
    queue<Node*> q;
    Node* temp = root;
    while(temp){
        ans.push_back(temp->data);
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            temp = temp->right;
        }
        else{
            if(!q.empty()){
                temp = q.front();
                q.pop();
            }
            else{
                temp = NULL;
            }
        }
    }
    for(auto x: ans){
        cout << x << " ";
    }

    
}
int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    printDiagonally(root);
    cout << endl;
    queueMethod1(root);
    return 0;
}