#include <bits/stdc++.h>
using namespace std;

void solve() {
		int n;
		cin >> n;
		vector<bool> good(n); // good[i] == true iff c_i == 0 (vertex i respects all its ancestors)
		vector<vector<int>> adj(n); // children list for each vertex (0-based indices)

		for (int i = 0; i < n; i++) {
				int parent, type;
				cin >> parent >> type;
				if (type == 0) good[i] = true; // mark vertices that respect all ancestors
				if (parent != -1) {
						adj[parent - 1].push_back(i); // add i as a child of (parent - 1); input uses 1-based indexing
				}
		}

		vector<int> ans; // stores deletable vertices (1-based indices) in required order
		for (int i = 0; i < n; i++) { // iterate in ascending order to satisfy "smallest index" tie-break
				if (good[i]) continue; // must not respect ancestors (c_i == 1)
				bool flag = true; // remains true if none of i's children respects i
				for (auto x : adj[i]) {
						if (good[x]) flag = false; // a child that respects ancestors also respects i -> i not deletable
				}
				if (flag) ans.push_back(i + 1); // convert to 1-based index for output
		}

		if (ans.size()) {
				for (auto x : ans) {
						cout << x << ' ';
				}
				cout << '\n';
		} else {
				cout << -1 << '\n'; // no vertex matches the deletion criteria
		}
}

int main() {
		cin.sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t = 1;
		// cin >> t;
		while (t--) {
				solve();
		}
}

/*
Time Complexity (TC): O(n)
Space Complexity (SC): O(n)
*/
