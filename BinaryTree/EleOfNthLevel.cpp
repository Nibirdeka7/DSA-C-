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
void eleNthLevel(Node* root, int curr,int level){ // Root Left Right
    if(root==NULL) return;
    if(curr==level) cout<<root->val<<" "; // work
    eleNthLevel(root->left,curr+1,level); // call 1
    eleNthLevel(root->right,curr+1,level); // call 2
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
    eleNthLevel(a,1,3);
    cout<<endl;
    
}