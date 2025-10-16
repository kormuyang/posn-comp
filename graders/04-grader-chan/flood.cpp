#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    // maxLeft[i] = max height from 0 to i
    // maxRight[i] = max height from n - 1 to i
    vector<int> maxLeft(n), maxRight(n);

    maxLeft[0] = h[0];
    for (int i = 1; i < n; i++) {
        maxLeft[i] = max(h[i], maxLeft[i - 1]);
    }

    maxRight[n - 1] = h[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        maxRight[i] = max(h[i], maxRight[i + 1]);
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        int mn = min(maxLeft[i], maxRight[i]);
        if (h[i] < mn) {
            ans += mn - h[i];
        }
    }
    cout << ans << '\n';
    return 0;
}