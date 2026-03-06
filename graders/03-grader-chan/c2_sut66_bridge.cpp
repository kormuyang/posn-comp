#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int)(5e3)
#define MOD (int)(1e9 + 7)

vector<vector<char>> a(2, vector<char>(MAX_N + 1));
vector<vector<int>> dp(2, vector<int>(MAX_N + 1));

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i <= 1; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    dp[0][0] = dp[1][0] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[0][i] == '.' && a[1][i] == '.') {
            dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
            dp[1][i] = dp[0][i];
        } else if (a[0][i] == '.' && a[1][i] == '#') {
            dp[0][i] = dp[0][i - 1];
            dp[1][i] = 0;
        } else if (a[0][i] == '#' && a[1][i] == '.') {
            dp[0][i] = 0;
            dp[1][i] = dp[1][i - 1];
        } else {
            dp[0][i] = 0;
            dp[1][i] = 0;
        }
    }
    cout << (dp[0][n] + dp[1][n]) % MOD << '\n';
}

int32_t main() {
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}