#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
class Queue{
public:
    Node* head;
    Node* tail;
    int s;
    Queue(){
        head=tail=NULL;
        s=0;
    }
    void push(int val){
        Node* temp=new Node(val);
        if(s==0) head=tail=temp;
        else{
            tail->next=temp;
            tail=temp;
        }
        s++;
    }
    
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next; 
        }

    }
    void pop(){
    if(s==0) cout<<"Queue is empty";
    else if(s>=1){
        Node* temp=head;
        head=head->next;
        s--;
        delete(temp);
    }
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
    void display(Node *head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next; 
        }
    }
    int size(){
        return s;
    }
};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.display();
    cout<<endl;
    cout<<q.front();
    cout<<endl;
    cout<<q.back();
    cout<<endl;
    cout<<q.size();
    cout<<endl;
    q.pop();
    q.display();
    cout<<q.front();
    cout<<endl;
    cout<<q.size();

}