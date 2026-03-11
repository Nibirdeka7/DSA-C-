#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>heights={2,1,5,6,2,3};
    int n=heights.size();
    stack<int>st;
    vector<int>nse;
    nse[n-1]=-1;
    st.push(heights[n-1]); 
    for(int i=n-2;i>=0;i++){
        while(st.size()>0 && st.top()>heights[i])
        st.pop();
        if(st.size()==0) nse[i]=-1;
        else nse[i]=st.top();
        st.push(heights[i]);
    }
    for(int i=0;i<n;i++)
     cout<<nse[i]<<" "; 
    vector<int>pse;

}