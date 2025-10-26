#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a_max, b_max, k;
    if (!(cin >> a_max >> b_max >> k)) return;

    vector<int> boy_ids(k);
    for (int i = 0; i < k; ++i) cin >> boy_ids[i];

    vector<int> girl_ids(k);
    for (int i = 0; i < k; ++i) cin >> girl_ids[i];

    long long total_choices = (long long)k * (k - 1) / 2;

    vector<int> boy_counts(a_max + 1, 0);
    vector<int> girl_counts(b_max + 1, 0);

    for (int id : boy_ids) {
        boy_counts[id]++;
    }
    for (int id : girl_ids) {
        girl_counts[id]++;
    }

    long long invalid_boy_pairs = 0;
    long long invalid_girl_pairs = 0;

    for (int count : boy_counts) {
        if (count >= 2) {
            invalid_boy_pairs += (long long)count * (count - 1) / 2;
        }
    }

    for (int count : girl_counts) {
        if (count >= 2) {
            invalid_girl_pairs += (long long)count * (count - 1) / 2;
        }
    }


    long long valid_ways = total_choices - invalid_boy_pairs - invalid_girl_pairs;

    cout << valid_ways << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        solve();
    }

    return 0;
}