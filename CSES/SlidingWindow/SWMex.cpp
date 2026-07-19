#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> freq(k + 1, 0);
    set<int> missing;

    // initially all numbers are missing
    for(int i = 0; i <= k; i++)
        missing.insert(i);

    // first window
    for(int i = 0; i < k; i++) {
        if(a[i] <= k) {
            freq[a[i]]++;
            if(freq[a[i]] == 1)
                missing.erase(a[i]);
        }
    }

    cout << *missing.begin() << " ";

    // sliding window
    for(int i = k; i < n; i++) {

        // remove old element
        int old = a[i-k];
        if(old <= k) {
            freq[old]--;
            if(freq[old] == 0)
                missing.insert(old);
        }

        // add new element
        int cur = a[i];
        if(cur <= k) {
            freq[cur]++;
            if(freq[cur] == 1)
                missing.erase(cur);
        }

        cout << *missing.begin() << " ";
    }
}