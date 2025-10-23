#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

long long count_factors(long long n, int base) {
    long long count = 0;
    if (n == 0) return 0;
    while (n > 0 && n % base == 0) {
        count++;
        n /= base;
    }
    return count;
}

void solve() {
    long long n, m;
    if (!(cin >> n >> m)) return;

    long long c2 = count_factors(n, 2);
    long long c5 = count_factors(n, 5);
    
    long long best_k = 1;

    while (c5 < c2 && best_k * 5 <= m) {
        best_k *= 5;
        c5++;
    }

    while (c2 < c5 && best_k * 2 <= m) {
        best_k *= 2;
        c2++;
    }

    
    long long factor_of_10 = 10;
    while (best_k * factor_of_10 <= m) {
        best_k *= factor_of_10;
    }


    
    long long max_k_multiplier = m / best_k;
    long long final_k = best_k * max_k_multiplier;
    

    if (final_k == 0) { 
        cout << n * m << "\n";
    } else {

        
        long long final_roundness = min(count_factors(n * final_k, 2), count_factors(n * final_k, 5));
        long long initial_roundness = min(count_factors(n * 1, 2), count_factors(n * 1, 5));

        if (final_roundness > initial_roundness) {
             cout << n * final_k << "\n";
        } else {
             cout << n * m << "\n";
        }
    }
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