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
class DLL{
    public:
        Node* head;
        Node* tail;
        int size;
        DLL(){
            head=tail=NULL;
            size=0;
        }
        void insertAtBeginning(int val){
            Node* temp=new Node(val);
            if(size==0) head=tail=temp;
            else{
                temp->next=head;
                head->prev=temp;
                head=temp;
            }
            size++;
        }
        void insertAtEnd(int val){
            Node* temp=new Node(val);
            if(size==0) head=tail=temp;
            else{
                tail->next=temp;
                temp->prev=tail;
                tail=temp;
            }
            size++;
        }
        void insertAtIdx(int idx,int val){
            if(idx<0 && idx>size) cout<<"Invalid";
            else if(idx==0) insertAtBeginning(val);
            else if(idx==size) insertAtEnd(val);
            else{
                Node* t=new Node(val);
                Node* temp=head;
                for(int i=1;i<=idx-1;i++){
                    temp=temp->next;
                }
                t->next=temp->next;
                temp->next=t;
                t->prev=temp;
                t->next->prev=t;
                size++;
            }
        }
        int getAtIdx(int idx){
            if(idx<0 && idx>=size){ 
                cout<<"Invalid";
                return -1;
                }
            else if(idx==0) return head->val;
            else if(idx==size) return tail->val;
            else{
                Node* temp=head;
                for(int i=1;i<=idx;i++) temp=temp->next;
                return temp->val;
            }
        }
        void display(){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->val<<" ";
                temp=temp->next; 
            }
    
    }
};