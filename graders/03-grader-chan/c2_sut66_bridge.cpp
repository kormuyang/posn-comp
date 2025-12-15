#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD (int)(1e9 + 7)

void solve() {
    int n;
    vector<string> s(2);
    cin >> n >> s[0] >> s[1];
    s[0] = ' ' + s[0];
    s[1] = ' ' + s[1];
    for (int i = 0; i < n; i++) {
        if ((s[0][i] == '#' || s[0][i + 1] == '#') && (s[1][i] == '#' || s[1][i + 1] == '#')) {
            cout << "0\n";
            return;
        }
    }
    vector<vector<int>> dp(2, vector<int>(n + 1, 0));
    dp[0][0] = dp[1][0] = 1;
    for (int i = 1; i <= n; i++) {
        if (s[0][i] == '.' && s[1][i] == '.') {
            dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
            dp[1][i] = dp[0][i];
        } else if (s[0][i] == '.') {
            dp[0][i] = dp[0][i - 1];
        } else if (s[1][i] == '.') {
            dp[1][i] = dp[1][i - 1];
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