//Print all the increasing sequences of length k from first n natural numbers.
#include<bits/stdc++.h>
using namespace std;
void subseq(vector<int> ans,vector<int>& v, int n,int k,int idx){
    if(idx==n){
        if(ans.size()==k){
            for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
            cout<<endl;          
        }
        return;
    }
    if(ans.size()+(n-idx)<k) return;
    int a=v[idx];
    subseq(ans,v,n,k,idx+1);
    v.push_back(a);
    subseq(ans,v,n,k,idx+1);   
    }

int main(){
    int k,n;
    cin>>k>>n;
    vector<int>v;
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }
    vector<int>ans;
    subseq(ans,v,n,k,0);
}