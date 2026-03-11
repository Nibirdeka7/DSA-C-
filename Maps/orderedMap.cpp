#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,int>m;
    m[1]=30;
    m[4]=96;
    m[2]=69;
    for(auto it : m){
        cout<<it.first<<" ";
    }
}