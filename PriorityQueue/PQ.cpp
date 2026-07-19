#include<bits/stdc++.h>
using namespace std;
class BinaryHeap{
public:
    int capacity;
    int size;
    int *arr;
    BinaryHeap(int cap){
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
    void Insert(int x){
        if (size == capacity){
            cout << "Binary Heap Overflow" << endl;
            return;
        }
        arr[size] = x;
        int k = size;
        size++;
        while(k != 0 && arr[parent(k)] > arr[k]){
            swap(arr[parent(k)], arr[k]);
            k = parent(k);
        }
    }
    void heapify(int ind){
        int ri = right(ind);
        int li = left(ind);
        int smallest = ind;
        if(li < size && arr[li] < arr[smallest]) smallest = li;
        if(ri < size && arr[ri] < arr[smallest]) smallest = ri;
        if(smallest != ind){
            swap(arr[ind], arr[smallest]);
            heapify(smallest);
        }
    }
    int getMin(){
        return arr[0];
    }
    int ExtractMin(){
        if(size <= 0) return INT_MAX;
    
        if(size == 1){
            size--;
            return arr[0];
        }
        int mini = arr[0];
        arr[0] = arr[size-1];
        size--;
        heapify(0);
        return mini;
    }
    
};