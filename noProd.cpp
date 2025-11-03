#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin>>n;
    vector<long long>a(n);

    for(long long i=0;i<n;i++){
        cin>>a[i];
    }

    vector<pair<long long,long long>>ans(n);

    if(a[0] > 0){
        ans[0].first = 1;
        ans[0].second = 0;
    }
    else{
        ans[0].first = 0;
        ans[0].second = 1;
    }

    for(long long i=1;i<n;i++){
        if(a[i] > 0){
            ans[i].first = ans[i-1].first + 1;
            ans[i].second = ans[i-1].second;
        }else{
            ans[i].first = ans[i-1].second;
            ans[i].second = ans[i-1].first + 1;
        }
    }

    long long p =0,neg=0;
    for(long long i=0;i<n;i++){
        p +=ans[i].first;
        neg += ans[i].second;
    }
    cout<<neg<<" "<<p<<endl;
}