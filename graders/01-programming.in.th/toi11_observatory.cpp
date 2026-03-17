#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> rec(n + 1, vector<int>(m + 1)), tri_l(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            rec[i][j] = a[i][j] + rec[i - 1][j] + rec[i][j - 1] - rec[i - 1][j - 1];
            tri_l[i][j] = a[i][j] + tri_l[i][j - 1] + tri_l[i - 1][j - 1] - tri_l[i - 1][j - 2];
        }
    }
    int ans = -(int)(1e9);
    for (int i = k; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            ans = max(ans, tri_l[i][j] - tri_l[i - k][j - k] - rec[i][j - k] + rec[i - k][j - k]);
        }
    }
    cout << ans << '\n';
    return 0;
}