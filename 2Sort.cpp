// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int solve() {
//     int n, k;
//     cin >> n >> k;
//     vector<long long> a(n);
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }

//     if (n < k + 1) {
//         return 0;
//     }

//     int l = 0, r = 1;
//     int cnt = 0;

//     while (r < n) {
//         if (a[r]*1LL*2 > a[r - 1]) {
//             r++;
//         } else {
//             l = r;
//             r = l + 1;
//         }

//         if (r - l + 1 == k + 1) {
//             cnt++;
//             l++;
//         }
//     }
//     return cnt;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     vector<int> results;

//     for (int i = 0; i < t; i++) {
//         results.push_back(solve());
//     }

//     for (int res : results) {
//         cout << res << "\n";
//     }

//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// The core logic is fixed to track the number of consecutive valid *steps* (r - l).
int solve() {
    int n, k;
    if (!(cin >> n >> k)) return 0;
    
    // Use long long for array elements and comparisons to prevent overflow (a_i up to 10^9).
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // k is the required number of inequalities (steps). Subarray length is k+1.
    // l and r track the start and end of the current run of valid *steps*.
    int l = 0;
    int total_valid_subarrays = 0;

    // We iterate 'r' from the second element (index 1) to the end.
    // 'r' always marks the right end of the current step being checked: a[r-1] < 2 * a[r].
    for (int r = 1; r < n; ++r) {
        
        // Correct Core Inequality Check: a[r-1] < 2 * a[r]
        // This is the simplified form of 2^(r-l-1) * a[r-1] < 2^(r-l) * a[r].
        if (a[r - 1] < 2 * a[r]) {
            // The run of valid steps continues. The window end is naturally extended by the loop.
            // The start 'l' remains the same.
        } else {
            // The consecutive run is BROKEN at the step between r-1 and r.
            // Any subarray starting at 'l' that includes 'r-1' has now failed.
            // The new valid run MUST start at the current position 'r'.
            l = r; 
        }

        // The length of the current run of valid *steps* is (r - l).
        // A run of 'k' steps corresponds to a subarray of length 'k+1'.
        if (r - l >= k) {
            // A valid subarray of length k+1 is formed, starting at index (r - k).
            total_valid_subarrays++;
        }
    }
    
    return total_valid_subarrays;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    
    // We can output results directly inside the loop to avoid using a results vector.
    while(t--) {
        cout << solve() << "\n";
    }

    return 0;
}