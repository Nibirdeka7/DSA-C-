// vector<int> inorderTraversal(TreeNode* root) {
//            // MORRIS TRAVERSAL
// TreeNode* curr = root;
// vector<int> ans;
// while(curr!=NULL){
//    if(curr->left!=NULL){
//        TreeNode* pred = curr->left;
//        while(pred->right!=NULL && pred->right!=curr){
//            pred = pred->right;
//        }
//        if(pred->right==NULL){ // link
//            pred->right=curr;
//            curr=curr->left;
//        }
//        if(pred->right==curr){ // unlink
//            pred->right=NULL;
//            ans.push_back(curr->val);
//            curr=curr->right;
//        }
//    }
//    else{
//        ans.push_back(curr->val);
//        curr=curr->right;
//    }

// }
//    return ans;
// }


// for practise

#include<bits/stdc++.h>
using namespace std;

vector<int>ans;

class Node {
  public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void MorrisTraversal(Node* root){
    Node* curr = root;
    while(curr != NULL){
        if(curr->left != NULL){
            Node* pred = curr->left;
            while(pred->right != NULL && pred->right != curr){
                pred = pred->right;
            }
            if(pred->right == NULL){ // link
                pred->right = curr;
                curr = curr->left;
            }
            if(pred->right == curr){ // unlink
                pred->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        else{
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }
}
int main(){

}