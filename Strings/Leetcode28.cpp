#include<bits/stdc++.h>
using namespace std;
int strStr(string haystack, string needle) {
        int h=haystack.length();
        int n=needle.length();
    for(int i=0;i<=h-n;i++){
        haystack=haystack;
        if(haystack.substr(i,n)==needle)
        return i;
        
    }
    return -1;
    }
int main(){
    string haystack,needle;
    cin>>haystack>>needle;

   cout<< strStr( haystack, needle); 
}