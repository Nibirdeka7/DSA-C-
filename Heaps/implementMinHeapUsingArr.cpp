#include<bits/stdc++.h>
using namespace std;
class minHeap{
public: 
    int arr[50];
    int idx;
    minHeap(){
        idx=1;
    }
    int top(){
        return arr[1];
    }
    void push(int x){
        arr[idx]=x;
        int i = idx;
        idx++;
        while(i!=1){
            int parent=i/2;
            if(arr[i]<arr[parent])  swap(arr[i],arr[parent]);
            else break;
            i=parent;
        }
    }
    void pop(){
        idx--;
        arr[1]=arr[idx];
        // rearrangrment
        int i=1;
        while(true){
            int left = 2*i, right = 2*i+1;
            if(left>idx-1) break;
            if(right>idx-1){
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
    int size(){
        return idx-1;
    }
};
int main(){
    minHeap pq;
    pq.push(2);
    pq.push(1);
    cout<<pq.top();
}