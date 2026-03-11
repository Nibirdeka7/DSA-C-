#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node( int val ){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* construct(int n, int arr[]){
    queue<Node*>q;
    Node* root = new Node (arr[0]);
    q.push(root);
    int i = 1, j = 2;
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        Node* l; 
        Node* r;
        if(arr[i] != INT_MIN) l = new Node (arr[i]);
        else l = NULL;
        if(arr[j] != INT_MIN)  r = new Node (arr[i]);
        else r = NULL;

        curr->left = l;
        curr->right = r;

        i+=2;
        j+=2;

    }
    return root;
}
int main() {

}