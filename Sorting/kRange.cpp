#include<bits/stdc++.h>
#include<climits>
using namespace std;
float max(float a,float b){
    if(a>=b) return a;
    else return b;
}
float min(float a,float b){
    if(a<b) return a;
    else return b;
}
int main(){
    int arr[]={5,3,6,8};
    int n=4;
    bool flag=true;
    float kmin= (float)(INT_MIN);
    float kmax= (float)(INT_MAX);
    for(int i=0;i<n-1;i++){
        if(arr[i]>=arr[i+1]){
            kmin= max(kmin,(arr[i]+arr[i+1])/2);
        }
        else{
            kmax= min(kmin,(arr[i]+arr[i+1])/2);
        }
        if(kmin>kmax){
            flag=false;
            break;
        }
    }
    if(flag==false) cout<<"-1";
    else cout<<kmin<<" "<<kmax;
}