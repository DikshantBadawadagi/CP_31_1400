#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

const long long INF = 200001;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long last_s = INF;
    long long last_t = INF;

    int total_penalty = 0;

    for (int current_val : a) {
        long long X = min(last_s, last_t);
        long long Y = max(last_s, last_t);

        if (current_val <= Y) {
            if (current_val <= X) {
                if (last_s <= last_t) {
                    last_s = current_val;
                } else {
                    last_t = current_val;
                }
            }
            else {
                if (last_s > last_t) {
                    last_s = current_val;
                } else {
                    last_t = current_val;
                }
            }
        }
        else {
            total_penalty++;

            if (last_s <= last_t) {
                last_s = current_val;
            } else {
                last_t = current_val;
            }
        }
    }

    cout << total_penalty << "\n";
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