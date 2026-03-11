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
Node* construct(int arr[], int n){
    queue<Node*>q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i=1;
    int j=2;
    while(q.size()>0 && i<n){
        Node* temp = q.front();
        q.pop();
        Node* l;
        Node* r;
        if(arr[i]!=INT_MIN) l=new Node(arr[i]);
        else l = NULL;
        if(j!=n && arr[j]!=INT_MIN) r=new Node(arr[j]);
        else r = NULL;

        temp->left=l;
        temp->right=r;

        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);

        i+=2;
        j+=2;
    }
    return root;
}
void leftBoundary(Node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
    cout<<root->val<<" ";
    leftBoundary(root->left);
    if(root->left==NULL) leftBoundary(root->right);
}
void leafNode(Node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL)
    cout<<root->val<<" ";
    leafNode(root->left);
    leafNode(root->right);
}
void rightBoundary(Node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
    cout<<root->val<<" ";
    if(root->right==NULL) rightBoundary(root->left);
    rightBoundary(root->right);
}
void boundary(Node* root){
    leftBoundary(root);
    leafNode(root);
    rightBoundary(root);
}
void PathSum2 (Node* root, vector<vector<int> >ans, vector<int> v,int targetSum) {
    if(root == NULL) return;
    if(root->left == NULL and root->right == NULL) {
        if(targetSum == root->val){
            v.push_back(root->val);
            ans.push_back(v);
        }
        return;
    }
    v.push_back(root->val);
    PathSum2(root->left, ans, v, targetSum - root->val);
    PathSum2(root->right, ans, v, targetSum - root->val);

}
Node* buildFromPREandIN(vector<int>pre, int prelo, int prehi, vector<int>in, int inlo, int inhi ) {
    if(prelo > prehi) return NULL;
    int i = inlo;
    Node* root = new Node (pre[prelo]);
    while(i < inhi) {
        if(pre[prelo] == in[i])
        i++;
    }
    int leftCount = i - inlo;
    int rightCount = inhi - i;
    root->left = buildFromPREandIN(pre, prelo+1, prelo+leftCount, in, inlo, i-1);
    root->right = buildFromPREandIN(pre, prelo+leftCount+1, prehi, in, i+1, inhi);
    return root;
}
int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,INT_MIN,28,INT_MIN,INT_MIN}; // INT_MIN means NULL
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
   // levelOrder(root);
    boundary(root);
}


