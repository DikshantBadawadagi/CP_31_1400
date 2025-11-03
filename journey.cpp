#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin>>n;

    vector<long long> a(n);
    vector<pair<long long,long long>> b(n);
    for(long long i=0;i<n;i++) {
        cin>>a[i];
        b[i].first = a[i] - (i+1);
        b[i].second = a[i];
    }

    sort(b.begin(), b.end());

    long long sum =0, maxi=0,curr = -1;

    for(long long i=0;i<n;i++){
        if(b[i].first != curr){
            curr = b[i].first;
            sum = b[i].second;
        }
        else{
            sum += b[i].second;
        
        }
        maxi = max(maxi, sum);
    }

    cout<<maxi<<endl;
    return 0;
    
}