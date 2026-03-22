#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int)(1e6)
#define MOD (int)(1e9 + 7)

vector<vector<int>> dp(MAX_N + 1, vector<int>(2));

int32_t main() {
    // dp[i][0] = the number of ways to build a tower of height i with the top layer separated
    // dp[i][1] = the number of ways to build a tower of height i with the top layer joined
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= MAX_N; i++) {
        dp[i][0] = ((4 * dp[i - 1][0]) % MOD + dp[i - 1][1]) % MOD;
        dp[i][1] = ((2 * dp[i - 1][1]) % MOD + dp[i - 1][0]) % MOD;
    }
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
    }
    return 0;
}