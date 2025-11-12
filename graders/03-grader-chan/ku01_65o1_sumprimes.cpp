#include <bits/stdc++.h>

using namespace std;

#define MAX_B 5010

vector<bool> is_prime(MAX_B * 3, true);

int main() {
    // Find all prime numbers
    for (int i = 2; i < MAX_B * 3; i++) {
        if (is_prime[i]) {
            for (int j = i * 2; j < MAX_B * 3; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // Input
    int a, b;
    cin >> a >> b;

    vector<int> prime_numbers;
    for (int i = a * 3; i <= b * 3; i++) {
        if (is_prime[i]) {
            prime_numbers.push_back(i);
        }
    }

    // Process
    int ans = 0;
    for (int i = a; i <= b; i++) {
        int sum = i * 3;
        for (auto &prime_number : prime_numbers) {
            if (prime_number < sum) {
                continue;
            }
            if (i + 2 * b < prime_number) {
                break;
            }
            int left = prime_number - sum;
            // mx -> max number
            int mx = min(left, b - i);
            // stars and bars
            int stars = 2 * mx - left, bars = 1;
            ans += ((stars + bars) + 1) / 2;
        }
    }

    // Output
    cout << ans << '\n';
    return 0;
}