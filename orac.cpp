#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;


    vector<long long> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }


    vector<int> dp(n + 1, 1);
    int max_length = 0;


    for (int i = 1; i <= n; ++i) {

        for (int d = 1; d * d <= i; ++d) {
            if (i % d == 0) {
                int j1 = d;
                
                int j2 = i / d;

                if (j1 < i) {
                    if (s[j1] < s[i]) {
                        dp[i] = max(dp[i], dp[j1] + 1);
                    }
                }

                if (j2 < i) { 
                    if (s[j2] < s[i]) {
                        dp[i] = max(dp[i], dp[j2] + 1);
                    }
                }
            }
        }
        max_length = max(max_length, dp[i]);
    }
    

    cout << max_length << "\n";
}

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        solve();
    }

    return 0;
}