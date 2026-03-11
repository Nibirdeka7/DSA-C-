//          1
//     2        3
// 4       5 6      7
// [[1],[3,2],[4,5,6,7]]
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
void nthLevel(Node* root,int curr,int level){
    if(root==NULL) return;
    if(level==curr){
        cout<<root->val<<" ";
        return;
    }
    nthLevel(root->left,curr+1,level);
    nthLevel(root->right,curr+1,level);
}
void nthLevelRev(Node* root,int curr,int level){
    if(root==NULL) return;
    if(level==curr){
        cout<<root->val<<" ";
        return;
    }
    nthLevelRev(root->right,curr+1,level);
    nthLevelRev(root->left,curr+1,level);
}
int level(Node* root){
    if(root==NULL) return 0;
    return 1 + max(level(root->left),level(root->right));
}
void levelOrder(Node* a){
    int n=level(a);
    for(int i=1;i<=n;i++){
       if(i%2!=0) nthLevel(a,1,i);
       else nthLevelRev(a,1,i);
       cout<<endl;
    }
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
    levelOrder(a);
    
}