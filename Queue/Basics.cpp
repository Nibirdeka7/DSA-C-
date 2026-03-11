#include<bits/stdc++.h>
using namespace std;
void display(queue<int>&q){
    int size = q.size();
    int i=0;
    while(size--){
        int x=q.front();
        cout<<x;
        q.pop();
        q.push(x); 
    }
    cout<<endl;
}
int main(){
    queue<int>q;
    // push
    // pop
    // front -> top
    // size, empty
    // back
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    // cout<<q.front()<<endl;
    // cout<<q.size();
    // q.pop();
    // cout<<q.front()<<endl;
    // cout<<q.size();
    // cout<<q.back();
    display(q);
    q.pop();
    display(q);
}