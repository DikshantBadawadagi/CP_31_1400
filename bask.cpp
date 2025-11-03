#include<bits/stdc++.h>
using namespace std;

long long f(int ind,int col, vector<vector<long long>>&arr, int n, vector<vector<long long>>&dp){
    if( ind == n ) return 0;

    if( dp[ind][col] != 0 ) return dp[ind][col];

    long long pick = arr[ind][col] + f(ind + 1,!col, arr,n,dp);

    long long notPick = max(f(ind + 1,0,arr,n,dp), f(ind + 1,1,arr,n,dp));

    return dp[ind][col] = max(pick, notPick);
}

int main() {
    int n;
    cin>>n;
    vector<vector<long long>>arr(n,vector<long long>(2,0));

    vector<vector<long long>>dp(n+1,vector<long long>(2,0));

    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>arr[j][i];
        }
    }


    for(int ind = n-1;ind>=0;ind--){
        for(int col=0;col<2;col++){
            long long pick = arr[ind][col] + dp[ind + 1][!col];

            long long notPick = max(dp[ind + 1][0], dp[ind + 1][1]);

            dp[ind][col] = max(pick, notPick);
        }
    }
    cout<<max(dp[0][0], dp[0][1])<<endl;
    //cout<<max(f(0,0,arr,n,dp), f(0,1,arr,n,dp))<<endl;
    return 0;
}