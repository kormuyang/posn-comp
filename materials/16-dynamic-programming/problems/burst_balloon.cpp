#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int)(5e2)

vector<int> a(MAX_N + 2);
vector<vector<int>> memo(MAX_N + 2, vector<int>(MAX_N + 2, -1));

// dp[l][r] = maximum score between l and r (excluding l and r)
int dp(int l, int r) {
    if (l > r) {
        return 0;
    }
    if (memo[l][r] != -1) {
        return memo[l][r];
    }
    int ret = 0;
    for (int k = l + 1; k < r; k++) {
        ret = max(ret, dp(l, k) + dp(k, r) + a[l] * a[k] * a[r]);
    }
    return memo[l][r] = ret;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = a[n + 1] = 1;
    cout << dp(0, n + 1) << '\n';
    return 0;
}