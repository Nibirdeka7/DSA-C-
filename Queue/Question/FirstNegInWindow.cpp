#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>a={0,-1,-2,3,4,-5,6,4,7,-8};
    vector<int>ans;
    int k=3;
    queue<int>q;
    int n=a.size();
    for(int i=0;i<n;i++){
        if(a[i]<0) q.push(i);
    }
    for(int i=0;i<n-k+1;i++){
       while(q.size()>0 && q.front()<i) q.pop();
       if(q.front()>=i+k || q.size()==0) ans.push_back(0);
       else ans.push_back(a[q.front()]);
    }
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
}