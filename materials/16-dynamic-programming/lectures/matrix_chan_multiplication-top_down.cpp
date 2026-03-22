#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int)(5e2)

vector<vector<int>> a(MAX_N, vector<int>(2));
vector<vector<int>> dp(MAX_N, vector<int>(MAX_N, -1));

int mcm(int l, int r) {
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    int ret = INT_MAX;
    for (int i = l; i < r; i++) {
        ret = min(ret, mcm(l, i) + mcm(i + 1, r) + a[l][0] * a[i][1] * a[r][1]);
    }
    return dp[l][r] = ret;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        dp[i][i + 1] = a[i][0] * a[i + 1][0] * a[i + 1][1];
    }
    cout << mcm(0, n - 1);
    return 0;
}