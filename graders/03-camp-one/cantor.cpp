#include <bits/stdc++.h>

using namespace std;

#define MAX_FAC 10

vector<int> fac(MAX_FAC + 1);

int main() {
    fac[1] = 1;
    for (int i = 2; i <= MAX_FAC; i++) {
        fac[i] = fac[i - 1] * i;
    }
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        if (n == 0) {
            cout << "0\n";
            continue;
        }
        int startIdx = 1;
        for (int i = MAX_FAC; i >= 2; i--) {
            if (n >= fac[i]) {
                startIdx = i;
                break;
            }
        }
        for (int i = startIdx; i >= 1; i--) {
            cout << n / fac[i];
            n %= fac[i];
        }
        cout << '\n';
    }
    return 0;
}