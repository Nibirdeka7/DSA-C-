#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int>m;
    pair<string,int>p1;
    p1.first="Nibir";
    p1.second=07;
    pair<string,int>p2;
    p2.first="Shahid";
    p2.second=10;
    pair<string,int>p3;
    p3.first="Binit";
    p3.second=39;
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);


    m["Akshay"]=8;
    for(auto p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<endl;
    m.erase("Binit");
    for(auto p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }
}
