#include <bits/stdc++.h>

using namespace std;

// Sqaure root of 2,000,000,000
#define MAX_N 45000

vector<bool> isPrime(MAX_N, true);
vector<int> primeFactors;

int main() {
    // Find all prime factors
    for (int i = 2; i < MAX_N; i++) {
        if (isPrime[i]) {
            primeFactors.push_back(i);
            for (int j = i + i; j < MAX_N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "-1\n";
            continue;
        }
        int start = n;
        vector<int> out;
        for (int i = 0; primeFactors[i] * primeFactors[i] <= n; i++) {
            if (n % primeFactors[i] == 0) {
                out.push_back(primeFactors[i]);
                while (n % primeFactors[i] == 0) {
                    n /= primeFactors[i];
                }
            }
        }
        if (n > 1) {
            out.push_back(n);
        }
        if (out.size() == 1 && out[0] == start) {
            cout << "-1\n";
        } else {
            for (int i = 0; i < out.size(); i++) {
                cout << out[i] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}