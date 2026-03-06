#include <bits/stdc++.h>

using namespace std;

#define MAX_VAL 1e6
#define INF 1e9

vector<int> dp(MAX_VAL);

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    dp[0] = 0; // base case
    for (int i = 1; i <= x; i++) {
        dp[i] = INF;
        for (auto &c : coins) {
            if (i - c >= 0) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    cout << (dp[x] == INF ? -1 : dp[x]) << '\n';
    return 0;
}