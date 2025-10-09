#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, r;
    cin >> l >> r;

    vector<bool> prime(r + 7, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i < r + 7; i++) {
        if (prime[i]) {
            for (int j = i * i; j < r + 7; j += i) {
                prime[j] = false;
            }
        }
    }

    int twin = 0, cousin = 0, sexy = 0;
    for (int i = l; i <= r; i++) {
        if (!prime[i]) {
            continue;
        }
        if (prime[i + 2] || (i - 2 >= 2 && prime[i - 2]))
            twin++;
        if (prime[i + 4] || (i - 4 >= 2 && prime[i - 4]))
            cousin++;
        if (prime[i + 6] || (i - 6 >= 2 && prime[i - 6]))
            sexy++;
    }

    cout << twin << '\n' << cousin << '\n' << sexy << '\n';

    return 0;
}
