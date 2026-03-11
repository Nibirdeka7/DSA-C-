#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int meetingRooms[n][2]={(1,10),(2,7),(3,19),(8,12),(10,20),(11,30)};
    vector<int>start;
    vector<int>end;
    for(int i=0;i<n;i++){
        start[i]=meetingRooms[i][0];
        end[i]=meetingRooms[i][1];
    }
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    int room = 0, ans = 0;
    int i=0, j=0;
    while(i<start.size()){
        if(start[i]<end[j]){
            room++;
            ans=max(ans,room);
            i++;
            
        }
        else if(start[i] > end[j]){
            j++;
            room--;
        }
        else{
            i++;
            j--;
        }
    }
}