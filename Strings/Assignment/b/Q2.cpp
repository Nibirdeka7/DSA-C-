// second largest
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int m=-1,sm=-1;
    for(int i=0;i<s.size();i++){
        int digV=s[i]-'0';
        if(digV>m){
            sm=m;
            m=digV;
        }
        else if(digV>sm && digV<m)
        sm=digV;
    }
    cout<<sm;
}