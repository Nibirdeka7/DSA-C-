#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
class Deque{
    public:
        Node* head;
        Node* tail;
        int s;
        Deque(){
            head=tail=NULL;
            s=0;
        }
        void pushFront(int val){
            Node* temp=new Node(val);
            if(s==0) head=tail=temp;
            else{
                temp->next=head;
                head->prev=temp;
                head=temp;
            }
            s++;
        }
        void pushBack(int val){
            Node* temp=new Node(val);
            if(s==0) head=tail=temp;
            else{
                tail->next=temp;
                temp->prev=tail;
                tail=temp;
            }
            s++;
        }
        int front(){
            if(s==0){
                 cout<<"Queue is empty";
                return -1;
            }
            return head->val;
        }
        int back(){
            if(s==0){
                cout<<"Queue is empty";
               return -1;
           }
           return tail->val; 
        }
        int size(){
            return s;
        }
        void display(){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->val<<" ";
                temp=temp->next; 
            }
    
    }
    };
int main(){
    
}