#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="Nibir Deka is a first year Undergraduate student of NIT Silchar";
    stringstream ss(s);
    string tmp;
    while(ss>>tmp){
        cout<<tmp<<endl;
    }
}