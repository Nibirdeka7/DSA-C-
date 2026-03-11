#include<bits/stdc++.h>
using namespace std;
int solve(int val1,int val2,char ch){
        if(ch=='+') return val1+val2;
        if(ch=='-') return val1-val2;
        if(ch=='*') return val1*val2;
        else return val1/val2;
    }
int main(){
    stack<int>val;
    string preS="79+4*8/3-";
    for(int i=0;i<preS.length();i++){
        if(preS[i]>=48 && preS[i]<57){
            val.push(preS[i]-48);
        }
        else{
            int val2=val.top();
            val.pop();
            int val1=val.top();
            val.pop();
            int ans=solve(val1,val2,preS[i]);
            val.push(ans);
        }
    }
    cout<<val.top();
}