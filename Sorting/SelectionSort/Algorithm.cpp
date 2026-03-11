#include<iostream>
#include<climits>
using namespace std;
int main(){
    int a[]={5,3,1,4,2};
    int n=5;
    for(int i=0; i<n-1; i++){
        int min = INT_MAX;
        int mindx = -1;
        for(int j=i; j<n;j++){
            if(a[j]<min){
                min = a[j];
                mindx = j;
            }
        }
        swap(a[i],a[mindx]);
    }
    for(int i=0; i<n; i++){
        cout<<a[i] <<" ";
    }
}