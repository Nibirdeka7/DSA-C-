#include <bits/stdc++.h>
using namespace std;
void heapify(int i, int arr[], int n){
    while(true){
        int left = 2*i, right = 2*i+1;
        if(left>=n) break;
        if(right>=n){
            if(arr[i]>arr[left]){
                swap(arr[i],arr[left]);
                i=left;
            }
            break;
        }
        if(arr[left]<arr[right]){
            if(arr[i]>arr[left]){
            swap(arr[i],arr[left]);
            i=left;
            }
            else break;
        }
        else{
            if(arr[i]>arr[right]){
            swap(arr[i],arr[right]);
            i=right;
            }
            else break;
        }
    }
}
int main()
{
    int arr[] = {-1, 5, 1, 3, 89, 56, 0, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = n / 2; i >= 1; i--)
    { // from n/2 bcz last ke n/2 elements leaf nodes hai aur woh pehle se hi heap me hai
        heapify(i,arr,n);
    }
    for(int j=0;j<n;j++) cout<<arr[j]<<" ";
}