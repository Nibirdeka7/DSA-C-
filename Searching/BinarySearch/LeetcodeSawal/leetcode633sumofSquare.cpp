#include<bits/stdc++.h>
using namespace std;
bool isPerfect(int n){
    int x=sqrt(n);
    if(x*x==n) return true;
    else return false;
}
bool SumofSquare(int c){
    int x=0,y=c;
    while(x<=y){
    if(isPerfect(x) && isPerfect(y)) return true;
    else if(!isPerfect(y)){  
        // instead of simply decreasing y-- it will take much more number of iterations 
        // so we decreased it this way
        y=(int)sqrt(y)*(int)sqrt(y);
        x=c-y;
    }
    else{ // x is not perfect
    // instead of simply increasing x++ it will take much more number of iterations 
    // so we increased it this way
       x=(int)sqrt(x)+1*(int)sqrt(x)+1;
       y=c-x;
    }
    }
}
int main(){
    int c;
    cin>>c;
    if(SumofSquare) cout<< "true";
    else "false";
}
    