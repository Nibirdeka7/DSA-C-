#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=23456;
    string s;
    s=to_string(n);
    int t=s.length();
    cout<<s.substr(t/2);
}