// Q2. Given an array of pairs of numbers of size N. In every pair, the first number is always smaller than the
// second number. A pair (c, d) can follow another pair (a, b) if b < c. The chain of pairs can be formed in this
// fashion. The task is to find the length of the longest chain which can be formed from a given set of pairs.
// Examples:
// : N = 5, arr={{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} }
// : 3
// The longest chain that can be formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}.
// : N = 2, arr={{5, 10}, {1, 11}}
// : 1
#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>a, vector<int>b ){
    return a[1] < b[1];
}
void display(vector<vector<int>>a){
    for(int i = 0; i < a.size(); i++){
        cout <<  "[" << a[i][0] << ","<< a[i][1] << "]" << ",";
    }
    
}
void ans(vector<vector<int>>arr){
    vector<vector<int>> res;
    sort(arr.begin(), arr.end(), cmp);
    int n = arr.size();
    res.push_back(arr[n-1]);
    for(int i = n-2; i>=0; i--){
        vector<int> curr = arr[i];
        if(curr[1] < res[res.size()-1][0]) res.push_back(curr);
    }
    reverse(res.begin(), res.end());
    display(res);
}

int main(){
    vector<vector<int>> arr={{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    ans(arr);
    
}