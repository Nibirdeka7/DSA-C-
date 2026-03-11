#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int>st;
    st.push(6); // 6
    st.push(7); // 6,7
    st.push(8); // 6,7,8
    st.push(9); // 6,7,8,9
    // st.pop();//6,7,8
    // cout<<st.size()<<endl;
    // cout<<st.top();
    stack<int>temp;
    while(st.size()!=0){
        int x=st.top();
        cout<<x<<" ";
        temp.push(x);
        st.pop();
    }
    cout<<endl;
   // stack<int>temp;
    while(temp.size()!=0){
       
        cout<<temp.top()<<" ";
       
        temp.pop();
    }
}