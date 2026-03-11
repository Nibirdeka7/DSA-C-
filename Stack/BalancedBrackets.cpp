#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<char>st;
    string s;
    cin>>s;
   // int size=0;
   if(s[0]==')') cout<<"Not Balanced";
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') {
            st.push('(');
            
        }
        else{
            if(st.size()==0) cout<<"Not Balanced";
            st.pop();
            
        }
    }
    if(st.size()==0) cout<<"Balanced";
    else cout<<"Not Balanced";
}