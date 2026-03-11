#include<bits/stdc++.h>
using namespace std;
void display(queue<int>&q){
    int size = q.size();
    int i=0;
    while(size--){
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x); 
    }
    cout<<endl;
}
void reverse(queue<int>&q){
    stack<int>st;
    int n=q.size();
    while(n--){
        st.push(q.front());
        q.pop();
    }
    while(st.size()!=0){
        q.push(st.top());
        st.pop();
    }
}
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    display(q);
    cout<<endl;
    reverse(q);
    display(q);
}