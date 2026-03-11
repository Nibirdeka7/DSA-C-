// Write a program to calculate the sum of odd numbers between a and b (both inclusive) using
// recursion.
#include<bits/stdc++.h>
using namespace std;
int print(int a,int b){
    if(a>b) return 0;
    if(a%2!=0){
        return a+print(a+1,b);
    }
    else return print(a+1,b);
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<print(a,b);
}