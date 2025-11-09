#include <bits/stdc++.h>

using namespace std;

#define MAX_E 1000

vector<int> e(MAX_E + 1, 0);

int main() {
    int n;
    cin >> n;
    int mn = MAX_E + 1, mx = 0;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        while (m--) {
            int l, r;
            cin >> l >> r;
            e[l]--;
            e[r]++;
            mn = min(mn, l);
            mx = max(mx, r);
        }
    }
    for (int i = 1; i <= mx; i++) {
        e[i] += e[i - 1];
    }
    bool flag = false;
    for (int i = mn; i < mx; i++) {
        if (e[i] == 0) {
            cout << i << ' ';
            while (i < mx && e[i] == 0) {
                i++;
            }
            cout << i << ' ';
            flag = true;
        }
    }
    if (!flag) {
        cout << -1;
    }
    return 0;
}