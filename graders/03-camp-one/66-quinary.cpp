#include <bits/stdc++.h>

using namespace std;

#define BASE 5

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (x == 0) {
            cout << "0\n";
            continue;
        }
        bool neg = (x < 0);
        x = abs(x);

        // Convert to Quinary
        vector<int> v;
        while (x > 0) {
            v.push_back(x % BASE);
            x /= BASE;
        }

        // Convert to Balanced Quinary
        v.push_back(0);
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] > 4) {
                v[i + 1] += 1;
                v[i] %= BASE;
            } else if (v[i] == 3) {
                v[i + 1] += 1;
                v[i] = -2;
            } else if (v[i] == 4) {
                v[i + 1] += 1;
                v[i] = -1;
            }
        }

        // Print Output
        for (int i = 0; i < v.size() - 1; i++) {
            cout << (neg ? -v[i] : v[i]) << ' ';
        }
        if (v.back() != 0) {
            cout << (neg ? -v.back() : v.back());
        }
        cout << '\n';
    }
    return 0;
}