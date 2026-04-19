#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 20;
const int MOD = 1e9 + 7;

vector<int> adj[MAX_N + 1];
int dp[1 << MAX_N][MAX_N + 1];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    dp[1][1] = 1;
    for (int mask = 1; mask < (1 << n) - 1; mask++) {
        if (mask & (1 << (n - 1))) {
            continue;
        }
        for (int u = 1; u < n; u++) {
            if (dp[mask][u] == 0) {
                continue;
            }
            for (int &v : adj[u]) {
                int new_mask = mask | (1 << (v - 1));
                if (mask == new_mask) {
                    continue;
                }
                dp[new_mask][v] = (dp[new_mask][v] + dp[mask][u]) % MOD;
            }
        }
    }
    cout << dp[(1 << n) - 1][n] << '\n';
    return 0;
}