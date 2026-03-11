#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={2,3,5,7,9,14};
    int target= 7;
    cout << lower_bound(arr.begin(),arr.end(), target)-arr.begin();
}