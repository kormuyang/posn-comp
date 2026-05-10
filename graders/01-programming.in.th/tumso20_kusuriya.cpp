#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_M = 16;
const int INF = 1e18;

int dp[1 << MAX_M];

int32_t main() {
    int n, m;
    cin >> n >> m;
    for (int k = 0; k < (1 << m); k++) {
        dp[k] = INF;
    }
    for (int i = 0, p; i < n; i++) {
        cin >> p;
        int msk = 0;
        for (int j = 0, x; j < m; j++) {
            cin >> x;
            msk = (msk << 1) + x;
        }
        dp[msk] = min(dp[msk], p);
    }
    for (int i = 0; i < m; i++) {
        for (int msk = 1; msk < (1 << m); msk++) {
            if (dp[msk] != INF && (msk & (1 << i))) {
                int sub_msk = msk ^ (1 << i);
                dp[sub_msk] = min(dp[sub_msk], dp[msk]);
            }
        }
    }
    for (int msk = 1; msk < (1 << m); msk++) {
        for (int sub_msk = (msk - 1) & msk; sub_msk > 0; sub_msk = (sub_msk - 1) & msk) {
            if (dp[sub_msk] != INF && dp[msk ^ sub_msk] != INF) {
                dp[msk] = min(dp[msk], dp[sub_msk] + dp[msk ^ sub_msk]);
            }
        }
    }
    cout << dp[(1 << m) - 1] << '\n';
    return 0;
}