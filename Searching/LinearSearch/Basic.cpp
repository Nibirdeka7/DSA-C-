#include<bits/stdc++.h>
using namespace std;
// best T.C O(1)
// worst T.C O(N) 
// used for small Data Set
// No additional Space is required
int search(vector<int>&arr,int x){
    int i;
    for(i=0;i<arr.size();i++){
        if(arr[i]==x) return i;
    }

     return -1;
}
int main(){
    vector<int> arr = {5,8,2,10,9};
    int x=4;
    int res=search(arr,x);
    cout<<res;
}