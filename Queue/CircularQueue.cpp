#include<bits/stdc++.h>
using namespace std;
class Queue{
public: 
    int f;
    int b;
    int s;
    vector<int> arr;
    Queue(int val){
        f = 0;
        b = 0;
        s = 0;
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
        s++;
    }
    void pop(){
        if(s==0){
            cout<<"Queue is empty";
            return;
        }
        f++;
        s--;
    }
    int front(){
        if(s==0){
            cout<<"Queue is empty";
            return -1;
        }
        return arr[f];
    }
    int back(){
        if(s==0){
            cout<<"Queue is empty";
            return -1;
        }
        return arr[b-1];
    }
    int size(){
        return s;
    }
    bool empty(){
        if(s==0) return true;
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