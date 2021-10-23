#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int val){
    Node* newNode = new Node();
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int findIndex(string s, int l, int r){
    if(r<l){
        return -1;
    }
    stack<char> ch;
    for(int i=l;i<=r;i++){
        if(s[i] == '('){
            ch.push(s[i]);
        }
        else if(s[i] == ')'){
            if(ch.top() == '('){
                ch.pop();
            }
            if(ch.empty()){
                return  i;
            }
        }
    }
    return -1;
}

Node* formTree(string str, int l, int r){
    if(r<l){
        return NULL;
    }
    cout << "l = " << l  << " " <<  r << endl;
    Node* root = createNode(abs(str[l] - '0'));
    int index = -1;
    cout << "l+1 = " << l+1 << " " <<  "r = " << r << str[l+1] << endl;
    if( l+1 <=r && str[l+1] == '('){
        cout << "inside" << endl;
        index = findIndex(str, l+1, r);
        cout << index << endl;
    }
    if(index!=-1){
        root->left = formTree(str, l+2, index-1);
        root->right = formTree(str, index+2, r-1);
    }
    return root;
}

void levelOrder(Node* root){
    if(!root){
        return;
    }
    // queue<Node*> q;
    // q.push(root);
    // while(q.empty()){
    //     Node* temp = q.front();
    //     cout << temp->data << " ";
    //     q.pop();
    //     if(root->left){
    //         q.push(temp->left);
    //     }
    //     if(root->right){
    //         q.push(temp->right);
    //     }
    // }
    cout << root->data << " ";
    levelOrder(root->left);
    
    levelOrder(root->right);
}

int main(){
    string str = "4(2(3)(1))(6(5)(8))";
    Node* root = formTree(str, 0, str.length() - 1);
    levelOrder(root);
    return 0;
}