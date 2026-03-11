#include<bits/stdc++.h>
using namespace std;
void displayrec(stack<int> &st){
    if(st.size()==0) return;
    cout<<st.top()<<" ";
    int x=st.top();
    st.pop();
    displayrec(st);
    st.push(x);
}
void pushAtBottom(stack<int>&st,int val){
    if(st.size()==0){
        st.push(val);
        return;
    }
    int x=st.top();
   // cout<<x<<" ";
    st.pop();
    pushAtBottom(st,val);
    st.push(x);

}
int main(){
    // at end
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    stack<int>t1;
    int val=69;
    pushAtBottom(st,val);
    displayrec(st);
}