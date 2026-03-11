#include<bits/stdc++.h>
using namespace std;
int main(){
// METHOD 1
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    stack<int>t1;
    stack<int>t2;
while(st.size()!=0){
    int x=st.top();
    t1.push(x);
    cout<<x<<" ";
    st.pop();
}
while(t1.size()!=0){
    int x=t1.top();
    t2.push(x);
    t1.pop();
}
while(t2.size()!=0){
    int x=t2.top();
    st.push(x);
    t2.pop();
}
cout<<endl;
while(st.size()!=0){
    cout<<st.top()<<" ";
    st.pop();
}

cout<<endl;
// METHOD 2;
    stack<int>st2;
    st2.push(10);
    st2.push(20);
    st2.push(30);
    st2.push(40);
    st2.push(50);
    vector<int>v;
    while(st2.size()!=0){
        v.push_back(st2.top());
        st2.pop();
    }
    for(int i=0;i<v.size();i++){
        st2.push(v[i]);
    }
    while(st2.size()!=0){
        cout<<st2.top()<<" ";
        st2.pop();
    }

}