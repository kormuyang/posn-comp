/*
Test Case #1
Input:
    15 5
    12 40
    2 20
    2 10
    4 10
    1 10
Output:
    70
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> weights(m + 1), values(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> weights[i] >> values[i];
    }
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= weights[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i]] + values[i]);
            }
        }
    }
    // for (int i = 0; i <= m; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << setw(3) << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[m][n] << '\n';
    return 0;
}