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
void displayTree(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}
int sum(Node* root){
    if(root==NULL) return 0;
    int ans = root->val + sum(root->left) + sum(root->right);
    return ans;
}
int product(Node* root){
    if(root==NULL) return 1;
    int ans = root->val*product(root->left)*product(root->right);
    return ans;
}
int size(Node* root){
    if(root==NULL) return 0;
    return 1+size(root->left)+size(root->right);
}
int maxNode(Node* root){
    if(root==NULL) return INT_MIN;
    // ek line mei karne ki NINJA TECHNIQUE
    // return max(root->val,max(maxNode(root->left),maxNode(root->right)));
    int lMax=maxNode(root->left);
    int rMax=maxNode(root->right);
    return max(root->val,max(lMax,rMax));
}
int minNode(Node* root){
    if(root==NULL) return INT_MAX;
    return min(root->val,min(minNode(root->left),minNode(root->right)));
}
int level(Node* root){
    if(root==NULL) return 0;
    return 1+ max(level(root->left), level(root->right));
}
void invert(Node* root){
    if(root==NULL) return;
    Node* temp = root->left;
    root->left=root->right;
    root->right=temp;
    invert(root->left);
    invert(root->right);
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

    displayTree(a);
    cout<<endl;
    cout<<sum(a)<<endl;
    cout<<size(a)<<endl;
    cout<<maxNode(a)<<endl;
    cout<<level(a)<<endl;
    invert(a);
    displayTree(a);

}