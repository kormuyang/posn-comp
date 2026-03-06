#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        if (i <= r) {
            dp[i][i] = 1;
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= r && j < i; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
    cout << dp[n][r];
    return 0;
}