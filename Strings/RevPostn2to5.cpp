// reverse from position 2 to 5 its the position not index
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    reverse(s.begin()+1,s.begin()+5);
    cout<<s;
}