#include<bits/stdc++.h>
using namespace std;
vector<int> st; // segment tree
vector<int> lazy;
void build_st(int arr[], int i, int lo, int hi) {
    if(lo == hi){
        st[i] = arr[lo];
        return;
    }
    int mid = lo + (hi-lo)/2;
    build_st(arr, 2*i+1, lo, mid);  // left
    build_st(arr, 2*i+2, mid+1, hi); // right
    st[i] = st[2*i+1] + st[2*i+2];
}
int getSum(int i, int lo, int hi, int l, int r){
    // check for pending lazy updates
    if(lazy[i]!=0){
        int rangeSize = hi-lo+1;
        st[i] += rangeSize*lazy[i];
        if(lo != hi){ // send lazy to left and right child
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(r<lo || l>hi) return 0; // IF range lies outside
    if(l<=lo && hi<=r) return st[i]; // subset
    int mid = lo+(hi-lo)/2;
    int left = getSum(2*i+1, lo, mid, l, r);
    int right = getSum(2*i+2, mid+1, hi, l, r);
    return left + right;
}
void updateRange(int i, int lo, int hi, int l, int r, int val){
     // check for pending lazy updates
    if(lazy[i]!=0){
        int rangeSize = hi-lo+1;
        st[i] += rangeSize*lazy[i];
        if(lo != hi){ // send lazy to left and right child
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(r<lo || l>hi) return; // IF range lies outside
    if(l<=lo && hi<=r){ // update entire [lo,hi]
        int rangeSize = hi-lo+1;
        st[i] += rangeSize*val;
        if(lo != hi){ // send lazy to left and right child
            lazy[2*i+1] += val;
            lazy[2*i+2] += val;
        }
        return;
    }
    int mid = lo + (hi - lo)/2;
    updateRange(2*i+1,lo,mid,l,r,val);
    updateRange(2*i+2,mid+1,hi,l,r,val);
    st[i] = st[2*i+1] + st[2*i+2];
}
int main(){
    int arr[] = {1, 4, 2, 8, 6, 4, 9, 3};
    int n = sizeof(arr)/4;
    st.resize(4*n);
    lazy.resize(4*n,0);
    build_st(arr, 0, 0, n-1); // arr, idx, lo, hi
    int l, r; // range of queries [l,r]
    cin >> l >> r;
    cout << getSum(0,0,n-1,l,r) << endl;
    int left, right, val;
    cin >> left >> right >> val;
    updateRange(0,0,n-1,left,right,val);
}   