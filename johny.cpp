#include <bits/stdc++.h>
using namespace std;

void solve() {
		long long n;
		cin >> n; 


		cout << 2 * n - __builtin_popcountll(n) << '\n';
}

int main() {
		ios::sync_with_stdio(false); // fast I/O
		cin.tie(nullptr);

		int t;
		cin >> t;
		while (t--) {
				solve();
		}
}


