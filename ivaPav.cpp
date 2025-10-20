#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> pref(31, vector<long long>(200006, 0));

long long rangeAND(int l, int r) {
    long long ans = 0;
    for (int i = 0; i < 31; i++) {
        long long count = pref[i][r + 1] - pref[i][l]; 
        if (count == (r - l + 1)) ans |= (1LL << i);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < 31; i++) {
            pref[i][0] = 0;
            for (int j = 0; j < n; j++) {
                pref[i][j + 1] = pref[i][j] + ((a[j] >> i) & 1);
            }
        }

        int q;
        cin >> q;
        while (q--) {
            long long l, k;
            cin >> l >> k;
            l--;

            if (a[l] < k) {
                cout << -1 << "\n";
                continue;
            }

            long long low = l, high = n - 1, res = l;

            while (low <= high) {
                long long mid = low + (high - low) / 2;
                long long curAND = rangeAND(l, mid);

                if (curAND >= k) {
                    res = mid;       
                    low = mid + 1;   
                } else {
                    high = mid - 1;  
                }
            }

            cout << res + 1 << endl;
        }
    }

    return 0;
}
