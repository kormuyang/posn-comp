#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N 1000

vector<vector<int>> a(MAX_N + 1, vector<int>(MAX_N + 1)), dp(MAX_N + 1, vector<int>(MAX_N + 1, INT_MIN));

int32_t main() {
    int n, m;
    cin >> n >> m;
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = a[i][j];
            if (i != 1 || j != 1) {
                dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
            }
            dp[i][j] = min(0LL, dp[i][j]);
        }
    }
    cout << abs(dp[n][m]) + 1 << '\n';
    return 0;
}