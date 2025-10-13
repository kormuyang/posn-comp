#include <bits/stdc++.h>

using namespace std;

int main() {
    // Input
    int a, b;
    cin >> a >> b;
    vector<bool> isPrime(b + 3, true);

    // Find all prime numbers
    for (int i = 2; i * i <= b + 2; i++) {
        if (!isPrime[i]) {
            continue;
        }
        for (int j = i + i; j <= b + 2; j += i) {
            isPrime[j] = false;
        }
    }

    // Find all Chen numbers
    vector<bool> isChen(b + 3, false);
    for (int i = 2; i <= b; i++) {
        if (!isPrime[i]) {
            continue;
        }
        if (isPrime[i + 2]) {
            isChen[i] = true;
        }
        for (int j = i + i; j <= b + 2; j += i) {
            if (isPrime[j / i] && isPrime[j - 2]) {
                isChen[j - 2] = true;
            }
        }
    }

    // Count all Chen numbers
    int ans = 0;
    for (int i = a; i <= b; i++) {
        ans += (isChen[i] ? 1 : 0);
    }
    cout << ans << '\n';
    return 0;
}