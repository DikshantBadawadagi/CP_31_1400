#include <bits/stdc++.h>
using namespace std;

void solve() {
		int n, k;
		cin >> n >> k;

		map<int, int> fr; 
		int cnt = 0;      

		for (int i = 0; i < n; i++) {
				int temp;
				cin >> temp;
				if (temp % k) {                  
						fr[k - temp % k]++;        
						cnt++;
				}
		}

		if (cnt == 0) {                       
				cout << 0 << '\n';
				return;
		}

		int ma = 0;                            
		int rem = 0;                          
		for (auto [x, y] : fr) {
				if (ma <= y) {
						ma = y;
						rem = x;
				}
		}


		cout << 1LL * (ma - 1) * k + rem + 1 << '\n';
}

int main() {
		ios::sync_with_stdio(false); 
		cin.tie(nullptr);

		int t;
		cin >> t;
		while (t--) {
				solve();
		}
}


