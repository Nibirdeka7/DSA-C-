#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int i=0,n=0;
    int len=s.length();
    while(s[i]!='\0'){
        if(len==1) break;
        else if(i==0){
            if(s[i]==s[i+1]) n++;
        }
        else if(i==len-1){
            if(s[i]==s[i-1]) n++;
        }
        else if((s[i]!=s[i-1]) && (s[i]!=s[i+1]) )
        n++;

        i++;
    }
    cout<<n;
}