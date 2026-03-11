//Write a recursive function to reverse a number. Avoid preceding 0s in the reversed number.
#include<bits/stdc++.h>
using namespace std;
void reverse(int n){
    if(n==0)
    return;
    else{
        cout<<n%10;
        reverse(n/10);
    }
}
int main(){
    int n;
    cin>>n;
   reverse(n);
}