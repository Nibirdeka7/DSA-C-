#include<bits\stdc++.h>
using namespace std;
int stair(int n){
    if(n==3) return 4;
    else if(n<=2) return n;
    return stair(n-3)+stair(n-2)+stair(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<stair(n);
}