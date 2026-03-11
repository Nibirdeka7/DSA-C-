// Given a string s of zeros and ones, return the maximum score after splitting the string
// into two non-empty substrings (i.e. left substring and right substring).
// The score after splitting a string is the number of zeros in the left substring 
//plus the number of ones in the right substring.

// Input: s = "011101"
// Output: 5 
// Explanation: 
// All possible ways of splitting s into two non-empty substrings are:
// left = "0" and right = "11101", score = 1 + 4 = 5 
// left = "01" and right = "1101", score = 1 + 3 = 4 
// left = "011" and right = "101", score = 1 + 2 = 3 
// left = "0111" and right = "01", score = 1 + 1 = 2 
// left = "01110" and right = "1", score = 2 + 1 = 3
#include<bits/stdc++.h>
using namespace std;
int maxScore(string s){
    int n=s.length();
    int mx=0,one_count=0;
    // count all 1's in the string
    for(int i=0;i<n;i++){
       if(s[i]=='1') one_count++;
    }
    int zero_count=0;
    // here we will iterate from then first element to before last element
    for(int i=0;i<n-1;i++){
        // if the pointed element is 1 then from the all 1's remove one
        if(s[i]=='1') one_count--;
        // if its 0 then zero_count is increaased by one
        else zero_count++;
        int ans=one_count+zero_count;
        if(mx<ans) mx=ans;
    }
    return mx;
}
int main(){
    string s;
    cin>>s;
    cout<< maxScore(s);
}