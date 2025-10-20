#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(int k,vector<long long> &a,vector<long long> &b,int n){
    int j = 0;
    for(int i=0;i<n;i++){
        if(a[j] >= b[i]){
            k--;
            if(k < 0) return false;
        }
        else{
            j++;
        }
    }
    return true;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<long long> a(n),b(n);
        a[0] = 1;
        for(int i=1;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        int low = 0, high = n;

        // while(low < high){
        //     int mid = low + (high - low)/2;
        //     if(check(mid,a,b,n)){
        //         high = mid;
        //     }
        //     else{
        //         low = mid + 1;
        //     }
        // }
        // cout<<low<<endl;

        int j = 0,k=0;
    for(int i=0;i<n;i++){
        if(a[j] >= b[i]){
            k++;
        }
        else{
            j++;
        }
    }
    cout<<k<<endl;
    }
}