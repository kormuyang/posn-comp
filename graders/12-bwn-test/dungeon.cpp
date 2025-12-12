#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> dp(n, 1e9);
    dp[n - 1] = max(1, 1 - a[m - 1][n - 1]);
    for (int j = n - 2; j >= 0; j--) {
        int need = dp[j + 1] - a[m - 1][j];
        dp[j] = max(1, need);
    }
    for (int i = m - 2; i >= 0; i--) {
        dp[n - 1] = max(1, dp[n - 1] - a[i][n - 1]);
        for (int j = n - 2; j >= 0; j--) {
            int need = min(dp[j], dp[j + 1]) - a[i][j];
            dp[j] = max(1, need);
        }
    }
    cout << dp[0];
    return 0;
}