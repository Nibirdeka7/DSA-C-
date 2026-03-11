#include<bits/stdc++.h>
using namespace std;
vector<int> st; // segment tree

void build_st(int arr[], int i, int lo, int hi) {
    if(lo == hi){
        st[i] = arr[lo];
        return;
    }
    int mid = lo + (hi-lo)/2;
    build_st(arr, 2*i+1, lo, mid);  // left
    build_st(arr, 2*i+2, mid+1, hi); // right
    st[i] = max(st[2*i+1], st[2*i+2]);
}
int getMax(int i, int lo, int hi, int& l, int& r){
    if(r<lo || l>hi) return INT_MIN; // IF range lies outside
    if(l<=lo && hi<=r) return st[i]; // subset
    int mid = lo+(hi-lo)/2;
    int left = getMax(2*i+1, lo, mid, l, r);
    int right = getMax(2*i+2, mid+1, hi, l, r);
    return max(left,right);
}
int main(){
    int arr[] = {1, 4, 2, 8, 6, 4, 9, 3};
    int n = sizeof(arr)/4;
    st.resize(4*n);
    build_st(arr, 0, 0, n-1); // arr, idx, lo, hi
    int l, r; // range of queries [l,r]
    cin >> l >> r;
    cout << getMax(0,0,n-1,l,r) << endl;
    // cout << getMin(0,0,n-1,l,r) << endl;
}   