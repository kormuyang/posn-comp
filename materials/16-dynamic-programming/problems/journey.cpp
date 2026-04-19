#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int MAX_N = 20;

int adj[MAX_N][MAX_N], dp[1 << MAX_N][MAX_N];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -INF;
        }
    }
    dp[1][0] = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (dp[mask][u] == -INF) {
                continue;
            }
            for (int v = 1; v < n; v++) {
                // mask = 11001, v = 1 -> new_mask = 11011
                int new_mask = mask | (1 << v);
                if (mask == new_mask) {
                    continue;
                }
                dp[new_mask][v] = max(dp[new_mask][v], dp[mask][u] + adj[u][v]);
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << '\n';
    return 0;
}