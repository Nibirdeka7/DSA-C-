#include<bits/stdc++.h>
using namespace std;
class Node{ // this is a tree node
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void preOrder(Node* root){ // Root Left Right
    if(root==NULL) return;
    cout<<root->val<<" "; // work
    preOrder(root->left); // call 1
    preOrder(root->right); // call 2
}
void inOrder(Node* root){ // Left Root Right
    if(root==NULL) return;
    inOrder(root->left); // call 1
    cout<<root->val<<" "; // work 
    inOrder(root->right); // call 2
}
void postOrder(Node* root){ // Left Root Right
    if(root==NULL) return;
    postOrder(root->left); // call 1
    postOrder(root->right); // call 2
    cout<<root->val<<" "; // work 
}
int main(){
    Node* a = new Node(1); // root
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;

    preOrder(a);
    cout<<endl;
    inOrder(a);
    cout<<endl;
    postOrder(a);
}