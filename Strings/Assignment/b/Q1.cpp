#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    string t=s;
    int n=s.size();
    reverse(s.begin(),s.end());
    cout<< t+s;

}