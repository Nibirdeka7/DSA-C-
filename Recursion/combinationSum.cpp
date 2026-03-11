// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
#include<bits/stdc++.h>
using namespace std;
void cSum(vector<int>v,int arr[],int target,int n,int idx){
    if(target==0){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(target<0) return;
    for(int i=idx;i<n;i++){
        v.push_back(arr[i]);
        cSum(v,arr,target-arr[i],n,i);
        v.pop_back(); // as jas dusri iteration hogi tab toh vector khali hoga
        
    }
}
int main(){
    int arr[]={2,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
    int target=8;
    cSum(v,arr,target,n,0);
}