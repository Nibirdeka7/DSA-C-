#include<bits/stdc++.h>
using namespace std;
 
#define quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using ll=long long;
 
string decimaltobinary(int n){
    string res="";
    while(n>0){
        if(n%2==1) res+='1';
        else res+='0';
        n=n/2;
    }
    reverse(res.begin(),res.end());
    return res;
}
bool checkpalindrome(string s){
    int n=s.size();
    for(int i=0;i<n/2;i++){
        if(s[i]==s[n-i-1]) continue;
        else{
            return false;
        }
    }
    return true;
}
bool check_palindrome(int n){
    int n1=n;
    int r=0;
    while(n>0){
        r=r*10+n%10;
        n=n/10;
    }
    if(r==n1) return true;
    else return false;
}
void solve(){
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(check_palindrome(i)){
            string s=decimaltobinary(i);
            if(checkpalindrome(s)) cnt++;
        }
 
    }
    cout<<cnt<<endl;
}
 
int main(){
    
    
    quick();
 
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}