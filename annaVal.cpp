#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        vector<int> zrr;
        for(auto num : nums) {
            string temp = to_string(num);
            int cnt = 0;
            for(int i = temp.length() - 1; i >= 0; i--) {
                if(temp[i] == '0') {
                    cnt++;
                } else {
                    break;
                }
            }
            zrr.push_back(cnt);
        }
        int ans = 0;
        vector<int> len;
        for(auto num : nums) {
            len.push_back(to_string(num).length());
        }
        for(int i = 0; i < n; ++i) {
            ans += len[i] - zrr[i]; 
        }
        sort(zrr.begin(), zrr.end(), greater<int>()); 
        for(int i = 0; i < n; ++i) {
            if(i & 1) ans += zrr[i]; 
        }
        cout << (ans - 1 >= m ? "Sasha" : "Anna") << "\n";
    }
    return 0;
}