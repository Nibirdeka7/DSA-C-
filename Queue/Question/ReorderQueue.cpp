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
int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    stack<int>st;
    int n=q.size();
    int x=n/2;
    while(x--){
        st.push(q.front());
        q.pop();
    }
    while(st.size()!=0){
        q.push(st.top());
        st.pop();
    }
    x=n/2;
    while(x--){
        st.push(q.front());
        q.pop();
    }
    while(st.size()!=0){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
    while(q.size()!=0){
        st.push(q.front());
        q.pop();
    }
    while(st.size()!=0){
        q.push(st.top());
        st.pop();
    }
    display(q);
    
}