// Distinct Query Character -> range will be given and we have to find the number of distinct characters in that range
#include<bits/stdc++.h>
using namespace std;

struct Node{
    vector<int>freq;
    Node(){
        freq.resize(26,0);
    }
};
vector<Node>tree;
string s;
Node merge(Node& a, Node& b){
    Node res;
    for(int i = 0; i < 26; i++){
        res.freq[i] = a.freq[i] + b.freq[i];
    }
    return res;
}
void build(int idx, int l, int r){
    if(l == r){
        tree[idx].freq[s[idx]-'0'] = 1;
        return;
    }
    int mid = (l+r)/2;
    build(2*idx+1, l, mid);
    build(2*idx+2, mid+1, r);
    tree[idx] = merge(tree[2*idx+1], tree[2*idx+2]);
}
void update(int idx, int l, int r, int pos, char c){
    if(l == r){
        fill(tree[idx].freq.begin(), tree[idx].freq.end(), 0);
        tree[idx].freq[c-'0'] = 1;
        return;
    }
    int mid = (l+r)/2;
    if(pos <= mid) update(2*idx+1, l, mid, pos, c);
    else update(2*idx+2, mid+1, r, pos, c);
    tree[idx] = merge(tree[2*idx+1], tree[2*idx+2]);
}
Node query(int idx, int l, int r, int ql, int qr){
    if(ql < l || r > qr) return Node();
    if(ql <= l && r <= qr) return tree[idx];
    int mid = (l+r)/2;
    Node L = query(2*idx+1, l, mid, ql, qr);
    Node R = query(2*idx+2, mid+1, r, ql, qr);
    return merge(L, R);
}
int main(){
    cin >> s;
    int n = s.size();
    tree.resize(4*n);
    build(0, 0, n-1);
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int pos;
            char c;
            cin >> pos >> c;
            pos--;
            s[pos] = c;
            update(0, 0, n-1, pos, c);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            Node res = query(0, 0, n-1, l, r);
            int distinct = 0;
            for(int x : res.freq) if(x > 0) distinct++;
            cout << distinct << endl;
        }
    }
}