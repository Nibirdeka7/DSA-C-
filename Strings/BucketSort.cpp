#include<bits/stdc++.h>
using namespace std;
string CountSort(string s){
    vector<int>arr(26,0);
    for(int i=0;i<s.size();i++){
        arr[s[i]-'a']++;
    }
    int j=0;
    for(int i=0;i<26;i++){
        while(arr[i]--){
            s[j++]=i+'a';
        }
    }
    return s;
}
int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;
    cout<< CountSort(s);

}