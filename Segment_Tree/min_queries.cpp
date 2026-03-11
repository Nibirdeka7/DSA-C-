#include<bits/stdc++.h>
using namespace std;
vector<int> st; // segment tree

void build_st_min(int arr[], int i, int lo, int hi) {
    if(lo == hi){
        st[i] = arr[lo];
        return;
    }
    int mid = lo + (hi-lo)/2;
    build_st_min(arr, 2*i+1, lo, mid);  // left
    build_st_min(arr, 2*i+2, mid+1, hi); // right
    st[i] = min(st[2*i+1], st[2*i+2]);
}

int getMin(int i, int lo, int hi, int& l, int& r){
    if(r<lo || l>hi) return INT_MAX; // IF range lies outside
    if(l<=lo && hi<=r) return st[i]; // subset
    int mid = lo+(hi-lo)/2;
    int left = getMin(2*i+1, lo, mid, l, r);
    int right = getMin(2*i+2, mid+1, hi, l, r);
    return min(left,right);

}

int main(){
    int arr[] = {1, 4, 2, 8, 6, 4, 9, 3};
    int n = sizeof(arr)/4;
    st.resize(4*n);
    build_st_min(arr, 0, 0, n-1); // arr, idx, lo, hi
    int l, r; // range of queries [l,r]
    cin >> l >> r;
    // cout << getMax(0,0,n-1,l,r) << endl;
    cout << getMin(0,0,n-1,l,r) << endl;
}   