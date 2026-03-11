#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="Nibir is an UG student at NITS, he is studying CSE and he is also the CR of the class";
    stringstream ss(s);
    string tmp;
    vector<string> str;
    while(ss>>tmp){
        str.push_back(tmp);
    }
   
    cout<<endl;
    sort(str.begin(),str.end());
   // for knowing the max count
    int count=1,mxcount=1;
    for(int i=1;i<str.size();i++){
        if(str[i]==str[i-1])
        count++;
        else count=1;
        if(count>mxcount) mxcount=count;
    }
    // for knowing the word
    count=1;
    for(int i=1;i<str.size();i++){
        if(str[i]==str[i-1])
        count++;
        else count=1;
        if(count==mxcount){
            cout<<str[i]<<" "<<mxcount;
        }
    }
}