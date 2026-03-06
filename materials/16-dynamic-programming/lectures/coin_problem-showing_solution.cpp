#include <bits/stdc++.h>

using namespace std;

#define MAX_VAL 1e6
#define INF 1e9

vector<int> dp(MAX_VAL);
vector<int> prv(MAX_VAL, -1);

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        dp[i] = INF;
        for (auto &c : coins) {
            if (i - c >= 0 && dp[i - c] + 1 < dp[i]) {
                dp[i] = dp[i - c] + 1;
                prv[i] = c;
            }
        }
    }
    if (dp[x] == INF) {
        cout << "-1\n";
        return 0;
    }
    cout << dp[x] << '\n';
    int cur = x;
    while (cur) {
        cout << prv[cur] << ' ';
        cur -= prv[cur];
    }
    cout << '\n';
    return 0;
}