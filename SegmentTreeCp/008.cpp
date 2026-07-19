// Sereja and Bracket 
// https://codeforces.com/contest/380/problem/C
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int matched, open, close;
    Node() : matched(0), open(0), close(0) {}
};
string s;
vector<Node>tree;
Node merge(Node &L, Node &R){
    Node res;
    int new_matched = min(L.open, R.close);
    res.matched = L.matched + R.matched + new_matched;
    res.close = L.close + R.close - new_matched;
    res.open = L.open + R.open - new_matched;

    return res;
}
void build(int idx, int l, int r){
    if(l == r){
        if(s[l] == '(') tree[idx].open = 1;
        else tree[idx].close = 1;
        return;
    }
    int mid = (l+r)/2;
    build(2*idx+1, l, mid);
    build(2*idx+2, mid+1, r);
    tree[idx] = merge(tree[2*idx+1], tree[2*idx+2]);
}
Node query(int idx, int l, int r, int ql, int qr){
    if(qr < l || r < ql) return Node();
    if(ql <= l && r <= qr) return tree[idx];
    int mid = (l+r)/2;
    Node left = query(2*idx+1, l, mid, ql ,qr);
    Node right = query(2*idx+2, mid+1, r, ql ,qr);
    return merge(left, right);
}

int main(){
    cin >> s;
    int n = s.size();
    tree.resize(4*n);
    build(0, 0, n-1);
    int m;
    cin >> m;
    while(m--){
        int l, int r;
        cin >> l >> r;
        l--, r--;
        Node res = query(0, 0, n-1, l, r);
        cout << res.matched*2 << endl;
    }
}