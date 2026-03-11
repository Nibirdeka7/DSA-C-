#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<char>st;
    string s;
    cin>>s;
    //st.push(s[0]);
    for(int i=0;i<s.length();i++){
        if(st.size()==0) st.push(s[i]);
        else{
            if(st.top()==s[i]) continue;
            else st.push(s[i]);
        }
    } 
    string ans;
    while(st.size()!=0){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}