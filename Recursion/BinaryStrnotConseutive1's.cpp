#include<bits/stdc++.h>
using namespace std;
void binaryStr(string ans,int k){
    if(ans.length()==k){
        cout<<ans<<"";
        cout<<endl;
        return;
    }
    binaryStr(ans+'0',k);
    if(ans.length()==0 || ans[ans.length()-1]!='1'){
    binaryStr(ans+'1',k);
    }
}
int main(){
    int k;
    cin>>k;
    binaryStr("",k); 
}