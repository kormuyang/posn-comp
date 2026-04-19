#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF (int)(1e9)

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 2, vector<int>(3, -INF));
    // dp[i][0] = maximum sum from 0 to i and the last move is 1-step
    // dp[i][1] = maximum sum from 0 to i and the last move is 2-step
    // dp[i][2] = maximum sum from 0 to i and the last move is 3-step
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for (int i = 1; i <= n + 1; i++) {
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + a[i];
        if (i >= 2) {
            dp[i][1] = max({dp[i - 2][0], dp[i - 2][1], dp[i - 2][2]}) + a[i];
        }
        if (i >= 3) {
            dp[i][2] = max(dp[i - 3][0], dp[i - 3][1]) + a[i];
        }
    }
    cout << max({dp[n + 1][0], dp[n + 1][1], dp[n + 1][2]}) << '\n';
    return 0;
}