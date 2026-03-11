#include<bits/stdc++.h>
using namespace std;
int main(){
    // at end
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    stack<int>t1;
    // while(st.size()!=0){
    //     t1.push(st.top());
    //     st.pop();
    // }
    // t1.push(60);
    // while(t1.size()!=0){
    //     st.push(t1.top());
    //     t1.pop();
    // }
    // while(st.size()!=0){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    // cout<<endl;
    // at idx
    int idx=2;
    int val=69;
    while(st.size()>idx){
        t1.push(st.top());
        st.pop();
    }
    st.push(val);
    while(t1.size()!=0){
        st.push(t1.top());
        t1.pop();
    }
    while(st.size()!=0){
        cout<<st.top()<<" ";
        st.pop();
    }
}