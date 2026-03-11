// Q4. Given two strings, determine if the first string can be transformed into the second string. The only
// operation allowed is moving a character from the first string to the front. If the string can be transformed,
// find the minimum number of operations required for the transformation.
// For example, the minimum number of operations required to convert the string ADCB to string ABCD is 3.
// ADCB —> CADB (Move ‘C’ to the front)
// CADB —> BCAD (Move ‘B’ to the front)
// BCAD —> ABCD (Move ‘A’ to the front)
#include<bits/stdc++.h>
using namespace std;
int min_steps( string given, string target) {
    int n = given.length();
    unordered_map<char,int> mp; // 
    for(int i = 0; i < n; i++){
        mp[given[i]]=i;
    }
    char curr_ch = target[n-1], prev_ch;
    int moves = 0;
    for(int i = n-2; i>=0; i--){
        prev_ch = curr_ch;
        curr_ch = target[i];
        if(mp[curr_ch] > mp[prev_ch]){
            moves++;
            mp[curr_ch] = 0 - moves;
        }
    }
    return moves;
}
int main(){
    string given;
    string target;
    cin >> given >> target;
    cout << min_steps(given, target);
}