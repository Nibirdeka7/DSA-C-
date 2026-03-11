#include<bits/stdc++.h>
using namespace std;
int main(){
    string str="brspeg";
    for(int i=0;i<str.length();i++){
        for(int j=0;j<str.length()-1-i;j++){
            if(str[j]>str[j+1]) 
            swap(str[j],str[j+1]);
        }
    }
    for(int i=0;i<str.length();i++)
    cout<<str[i];
}