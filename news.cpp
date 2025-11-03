#include <bits/stdc++.h>

using namespace std;

vector<int> parent, sz; // DSU arrays: parent[i] is representative of i, sz[i] is size of the component led by i

int find(int a) {
		if (a == parent[a]) return a; // found representative of the set
		return parent[a] = find(parent[a]); // path compression for efficiency
}

void join(int a, int b) {
		a = find(a); // find leader of a
		b = find(b); // find leader of b
		if (a == b) return; // already in the same set
		if (sz[a] < sz[b]) swap(a, b); // union by size: ensure a is larger
		parent[b] = a; // attach b's tree under a
		sz[a] += sz[b]; // update size of the resulting set
}

void solve() {
		int n, m;
		cin >> n >> m;

		parent.resize(n);
		for (int i = 0; i < n; i++) parent[i] = i; // initially each user is its own parent
		sz.resize(n, 1); // each set has size 1 at the beginning

		for (int i = 0; i < m; i++) { // O((sum k_i) * alpha(n)) over all unions
				int k;
				cin >> k; // number of users in this group
				if (k > 0) { // skip empty groups safely
						int first;
						cin >> first; // first member of the group
						first--; // to 0-based index
						for (int j = 1; j < k; j++) { // connect everyone in this group to 'first'
								int a;
								cin >> a;
								a--; // to 0-based index
								join(first, a); // merge sets so the whole group becomes connected
						}
				}
		}

		for (int i = 0; i < n; i++) { // O(n * alpha(n)) to find representatives and print sizes
				cout << sz[find(i)] << ' '; // size of the connected component for user i
		}
}

int main() {
		cin.sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		solve();
}

// Time Complexity (TC): O((sigma k_i + n) * alpha(n))
// Space Complexity (SC): O(n)
