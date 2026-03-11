#include<bits\stdc++.h>
using namespace std;
int stair(int n){
    if(n<=2) return n;
    return stair(n-2)+stair(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<stair(n);
}