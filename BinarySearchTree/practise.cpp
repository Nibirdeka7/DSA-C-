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
Node* insert(Node* root, int val){
    if(root->val > val) { // go left
        if(root->left == NULL) {
            Node* temp = new Node (val);
            root -> left = temp;
        }
        else insert(root->left, val);
    }
    else {
        if(root->right == NULL){
            Node* temp = new Node (val);
            root->right = temp;
        }
        else insert(root->right, val);
    }
    return root;
}
int main(){

}