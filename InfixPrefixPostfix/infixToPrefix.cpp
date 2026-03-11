#include<bits/stdc++.h>
using namespace std;
int priority(char ch){
    if(ch=='+' || ch=='-') return 1;
    else return 2;
}
int main(){
    string s="2+6*4/8-3";
    stack<string>val;
    stack<char>op;
    for(int i=0;i<s.length();i++){
        if(s[i]>=48 && s[i]<=57) val.push(to_string(s[i]-48));
        else{
            if(op.size()==0) op.push(s[i]);
            else if(priority(op.top())<priority(s[i]))
            op.push(s[i]);
            else{
                while(op.size()>0 && priority(s[i])<=priority(op.top())){
                    char ch=op.top();
                    op.pop();
                    string val2=val.top();
                    val.pop();
                    string val1=val.top();
                    val.pop();
                    string ans=ch+val1+val2;
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
                char ch=op.top();
                op.pop();
                string val2=val.top();
                val.pop();
                string val1=val.top();
                val.pop();
                string ans=ch+val1+val2;
                val.push(ans);
                
                cout<<val.top();
}