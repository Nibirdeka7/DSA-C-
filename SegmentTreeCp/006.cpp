// K Query -> range will be give and we have to find the number of elements in that range which are greater than k
#include<bits/stdc++.h>
using namespace std;
vector<int>merge(vector<int>&a, vector<int>&b){
    vector<int>ans;
    int i=0, j=0;
    int n = a.size(), m = b.size();
    while(i < n && j < m){
        if(a[i] < b[j]){
            ans.push_back(a[i]);
            i++;
        }
        else{
            ans.push_back(b[j]);
            j++;
        }
    }
    while(i < n){
        ans.push_back(a[i]);
        i++;
    }
    while(j < m){
        ans.push_back(b[j]);
        j++;
    }
    return ans;
}

vector<vector<int>>tree;
vector<int>arr;
void build(int idx, int l, int r){
    if(l == r){
        tree[idx] = {arr[l]};
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx + 1, l, mid);
    build(2 * idx + 2, mid + 1, r);
    tree[idx] = merge(tree[2 * idx + 1], tree[2 * idx + 2]);
}
int query(int idx, int l, int r, int ql, int qr, int k){
    if(r < ql || l > qr) return 0;
    if(l >= ql && r <= qr){
        int pos = upper_bound(tree[idx].begin(), tree[idx].end(), k) - tree[idx].begin();
        return tree[idx].size()-pos;
    }
    int mid = (l+r)/2;
    int left = query(2*idx+1, l , mid, ql, qr, k);
    int right = query(2*idx+2, mid+1, r, ql , qr, k);
    return left+right;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    arr.resize(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    tree.resize(4*n);
    build(0, 0, n-1);

    int q;
    cin >> q;
    while(q--){
        int l, r, k;
        cin >> l  >> r >> k;
        cout << query(0, 0, n-1, l-1, r-1, k) << endl;
    }
}