#include<bits/stdc++.h>
using namespace std;
bool isPS(int n){
    int x=sqrt(n);
    if(x*x==n) return true;
    else return false;
}
bool judge(int c){
    int x=0,y=c;
    while(x<=y){
    if(isPS(x) && isPS(y)){
        return true;
    } else if(!isPS(y)){
        y=(int)sqrt(y)*(int)sqrt(y);
        x=c-y;
    } else{
        x=(int)(sqrt(x)+1)*(int)(sqrt(x)+1);
        y=c-x;
    }
}
    
    return false;
}
int main(){
    int c=41;
    cout<<judge(c);
}