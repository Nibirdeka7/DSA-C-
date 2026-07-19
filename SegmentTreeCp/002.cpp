#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class SegmentTree {
private:
    vector<ll>tree;
    vector<ll>arr;
    int n;
    void build(int idx, int l, int r){
        if(l == r){
            tree[idx] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        build(idx*2+1, l, mid);
        build(idx*2+2, mid+1, r);
        tree[idx] = min(tree[idx*2+1] , tree[idx&2+2]);
    }
    ll query(int idx, int l, int r, int qr, int ql){
        if(ql > r || qr < l) return INT_MAX;
        if(ql <= l && r <= qr) return tree[idx];
        int mid = (l+r)/2;
        ll leftRes = query(2*idx+1, l, mid, ql, qr);
        ll rightRes = query(2*idx+2, mid+1, r, ql, qr);

        return min(leftRes, rightRes);
    }
    void update(int idx, int l, int r, int pos, int newVal){
        if(l == r){
            arr[l] = newVal;
            tree[idx] = newVal;
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid) update(2*idx+1, l, mid, pos, newVal);
        else update(2*idx+2, mid+1, r, pos, newVal);
        tree[idx] = min(tree[2*idx+1], tree[2*idx+2]);
    }
public:
    SegmentTree(const vector<ll>&input){
        arr = input;
        n = arr.size();
        tree.resize(4*n);
        build(0, 0, n-1);
    }
    ll getSum(int l, int r){
        return query(0, 0, n-1, l, r);
    }
    void setValue(int pos, ll newVal){
        update(0, 0, n-1, pos, newVal);
    }
};

