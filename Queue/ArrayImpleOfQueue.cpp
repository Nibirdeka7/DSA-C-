#include<bits/stdc++.h>
using namespace std;
class Queue{
public: 
    int f;
    int b;
    vector<int> arr;
    Queue(int val){
        f = 0;
        b = 0;
        vector<int>v(val);
        arr=v;
    }
    void push(int val){
        if(b==5){
            cout<<"Queue is full";
            return;
        }
        arr[b]=val;
        b++;
    }
    void pop(){
        if(f-b==0){
            cout<<"Queue is empty";
            return;
        }
        f++;
    }
    int front(){
        if(f-b==0){
            cout<<"Queue is empty";
            return -1;
        }
        return arr[f];
    }
    int back(){
        if(f-b==0){
            cout<<"Queue is empty";
            return -1;
        }
        return arr[b-1];
    }
    int size(){
        return b-f;
    }
    bool empty(){
        if(b-f==0) return true;
        else return false;
    }
    void display(){
        for(int i=f;i<b;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};
int main(){
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.display();
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