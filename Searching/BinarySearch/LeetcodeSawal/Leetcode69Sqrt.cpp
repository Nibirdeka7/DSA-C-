#include<bits/stdc++.h>
using namespace std;
int main(){
    int x=36;
    int l=0;
    int h=x;
    int m=(l+h)/2;
    int s=m*m;
    while(l<=h){
        if(s==x) cout<< m;
        if(s>x) h=m-1;
        else l=m+1; 
    }
}