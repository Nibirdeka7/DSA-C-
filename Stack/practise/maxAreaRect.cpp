#include<bits/stdc++.h>
using namespace std;
int maxArea(int n,int h[]){
    int nsi[n];
    nsi[n-1] = n;
    stack<int>st;
    st.push(n-1);
    for(int i = n-2; i>=0; i--){
        while(st.size() > 0 and h[st.top()] >= h[i]) st.pop();
        if(st.size() == 0) nsi[i] = n;
        else nsi[i] = st.top();
        st.push(i);
    } 
    int psi[n];
    psi[0] = -1;
    stack<int>gt;
    gt.push(0);
    for(int i = 1; i < n; i++){
        while(gt.size() > 0 and h[gt.top()] >= h[i]) gt.pop();
        if(gt.size() == 0) psi[i] = -1;
        else psi[i] = gt.top();
        gt.push(i);
    }
    int maxArea = INT_MIN;
    int area;
    for(int i = 0; i < n; i++){
        area = h[i] * (nsi[i]-psi[i]-1);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}
int main(){
    int n; 
    cin >> n;
    int heights[n];
    for(int i = 0; i < n; i++) cin >> heights[i];
    cout <<  maxArea(n,heights);
}