#include<bits/stdc++.h>
using namespace std;
int main(){
    string arr[]={"123","00821","0460","1020","2300","0001"};
    int a=stoi(arr[0]);
    for(int i=1;i<=5;i++){
        int x=stoi(arr[i]);
        if(x>a) a=x;
    }
    cout<<a;
}