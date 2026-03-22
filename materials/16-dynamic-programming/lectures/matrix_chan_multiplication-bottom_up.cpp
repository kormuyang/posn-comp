#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int)(5e2)

vector<vector<int>> a(MAX_N, vector<int>(2));
vector<vector<int>> dp(MAX_N, vector<int>(MAX_N));

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }
    for (int len = 2; len < n; len++) {
        for (int i = 0; i + len < n; i++) {
            int j = i + len;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i][0] * a[k][1] * a[j][1]);
            }
        }
    }
    cout << dp[0][n - 1];
    return 0;
}