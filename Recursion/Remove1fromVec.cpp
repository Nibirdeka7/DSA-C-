#include<bits/stdc++.h>
using namespace std;
void remove1(vector<int>ans,vector<int>original,int idx){
    if(idx==original.size()){
        for(int i=0;i<) cout<<ans[it]<<endl;
        return;
    }
    int ch=original[idx];
    if(ch==1) remove1(ans,original,idx+1);
    else remove1(ans.push_back(original[idx]),original,idx+1);
   
}
int main(){
    vector<int>v;
    for(auto it:v) cin>>v[it];
    vector<int>ans;
    remove1(ans,v,0);
}
