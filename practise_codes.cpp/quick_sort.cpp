#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int si, int ei){
    int pivotEle = arr[(si+ei)/2];
    int count = 0;
    for(int i = si; i <= ei; i++){
        if(i==(si+ei)/2) continue;
        if(arr[i]<=arr[pivotEle]) i++;
    }
    int pivotIdx = si + count;
    int i = si, j = ei;
    while(i<pivotIdx && j>pivotIdx){
        if(arr[i]<pivotEle) i++;
        if(arr[j]>pivotEle) j--;
        else if(arr[i]>pivotEle && arr[j]<=pivotEle){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        return pivotIdx;
    } 
}
void quickSort(int arr[], int si, int ei){
    if(si>=ei) return;
    int pi = partition(arr,si,ei);
    quickSort(arr,si,pi-1);
    quickSort(arr,pi+1,ei);
}
int main(){
    int arr[]={-1,5,2,7,9,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
}