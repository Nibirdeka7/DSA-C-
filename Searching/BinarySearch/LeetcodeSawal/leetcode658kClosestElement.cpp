#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a={1,2,3,4,6}; 
    int x=3,k=4;
    vector<int> ans(k);
    int lo=0,hi=a.size()-1;
    bool flag=false;
    int t=0;
    int mid;
    while(lo<=hi){ 
        mid=lo+(hi-lo)/2;
        if(a[mid]==x){
            flag=true;
            ans[t]=a[mid];
            t++;
            break;
        }
        else if(a[mid]>x) hi=mid-1;
        else lo=mid+1;
    }
    int lb=hi;
    int ub=lo;
    if(flag==true){
        lb=mid-1;
        ub=mid+1;
    }

    while(t<k && lb>=0 && ub<=hi){
            int d1=abs(x-a[lb]);
            int d2=abs(x-a[ub]);
        if(d1<=d2){
            ans[t]=a[lb];
            lb--;
        }
        else {
            ans[t]=a[ub];
            ub++;
        }
        t++;
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<k;i++){
        cout<< ans[i];
    }
}