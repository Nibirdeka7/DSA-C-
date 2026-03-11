#include<bits/stdc++.h>
using namespace std;
class Stack{ // user defined data structure
public:
    vector<int> arr;
    int idx = -1;
    void push(int val){
        arr.push_back(val);
    }
    void pop(){
        if(arr.size()==0){
            cout<<"Stack is empty";
            return;
        }
        arr.pop_back();
    }
    int top(){
        if(arr.size()==0){
            cout<<"Stack is empty";
            return -1;
        }
        return arr[arr.size()-1];
    }
    int size(){
        return arr.size();
    }
    void display(){
        for(int i=0;i<=idx;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(40);
    st.pop();
    cout<<st.size();
}