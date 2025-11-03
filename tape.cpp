#include <bits/stdc++.h>
using namespace std;

void solve() {
		int n, m, k;
		cin >> n >> m >> k;

		int a[n];
		for (int i = 0; i < n; i++) {
				cin >> a[i];
		}

		// Positions may already be sorted by input, but sort to be safe for gap computation
		sort(a, a + n);

		int diff[n - 1];
		for (int i = 0; i < n - 1; i++) {
				// Gap of intact (non-broken) segments between consecutive broken ones
				// If we cover both sides with one tape piece, we must also cover this gap
				diff[i] = a[i + 1] - a[i] - 1;
		}

		// To use at most k pieces, we keep k groups by placing cuts across the (k-1) largest gaps
		// Equivalently, we "pay" for merging across the smallest (n - k) gaps
		sort(diff, diff + n - 1);

		int ans = n; // Base cost: each broken segment requires at least length 1 if covered individually
		for (int i = 0; i < n - k; i++) {
				// Merge groups across the smallest (n - k) gaps; add their lengths to the total tape length
				ans += diff[i];
		}

		cout << ans << '\n';
}

int main() {
		cin.sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		solve();
}

/*
Time Complexity (TC): O(nlogn)
Space Complexity (SC): O(n)
*/
