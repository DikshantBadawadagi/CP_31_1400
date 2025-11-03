#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mpp[arr[i]]++;
        }
        long long ans=0;
        vector<int>vis(n+1,0);
        
        for(auto it : mpp){
            int cnt = it.second;

            if(vis[cnt]){
                ans+=max((cnt - vis[cnt]),0);
                vis[cnt]++;
            }
            else{
                vis[cnt]++;
                ans+=cnt;
            }
        }
        cout<<ans<<endl;
        
    }
}