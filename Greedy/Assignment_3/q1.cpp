// Q1. Given a string s of ‘(‘ , ‘)’ and lowercase English characters. Your task is to remove the minimum number
// of parentheses ( ‘(‘ or ‘)’, in any positions ) so that the resulting parentheses string is valid and return any
// valid string.
// Formally, a parentheses string is valid if and only ifG
// B It is the empty string, contains only lowercase characters, oK
// B It can be written as AB (A concatenated with B), where A and B are valid strings, oK
// B It can be written as (A), where A is a valid string0
// B
// Example 1:
// : s = “lee(t(c)o)de)”
// : “lee(t(c)o)de”
// Explanation: “lee(t(co)de)” , “lee(t(c)ode)” would also be accepted.
#include<bits/stdc++.h>
using namespace std;
string valid_parentheses(string s){
    int n = s.size();
    string a = "";
    int balance = 0;
    // left to right
    for(int i = 0; i < n; i++){
        char n = s[i];
        if( n == '('){
            a += n;
            balance ++;
        } else if( n == ')'){
            if(balance > 0){
                a += n;
                balance--;
            }
        } else{
            a += n;
        }
    }

    // right to left
    string b = "";
    balance = 0;
    for(int i = n-1; i > 0; i--){
        char n = s[i];
        if( n == ')'){
            b += n;
            balance ++;
        } else if( n == '('){
            if(balance > 0){
                b += n;
                balance--;
            }
        } else{
            b += n;
        }

    }
    reverse(b.begin(),b.end());
    return b;
}
int main(){
    cout << valid_parentheses("(a(b(c)))d)");
}