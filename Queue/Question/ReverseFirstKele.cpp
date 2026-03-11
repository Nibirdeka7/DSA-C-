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
void revFirstKM1(queue<int>&q,int k){
    stack<int>rev;
    stack<int>newe;
    int s=q.size();
    while(s--){
        rev.push(q.front());
        q.pop();
    }
    int n=rev.size();
    int rem=n-k;
    while(rem--){
        newe.push(rev.top());
        rev.pop();
    }
    while(rev.size()!=0){
        q.push(rev.top());
        rev.pop();
    }
    while(newe.size()!=0){
        q.push(newe.top());
        newe.pop();
    }
}
void revFirstKM2(queue<int>&q,int k){
    stack<int>st;
    int n=q.size();
    int rem=n-k;
    while(k--){
        st.push(q.front());
        q.pop();
    }
    while(st.size()!=0){
        q.push(st.top());
        st.pop();
    }
    while(rem--){
        int x=q.front();
        q.push(x);
        q.pop();
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
    int k=3;
    // revFirstKM1(q,k);
    // display(q);
    revFirstKM2(q,k);
    display(q);
}