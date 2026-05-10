#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 150;
const int INF = 1e9;
const vector<pair<int, int>> DIR = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int g[MAX_N + 1][MAX_N + 1];
int d_s[MAX_N + 1][MAX_N + 1];
int d_e[MAX_N + 1][MAX_N + 1];

int main() {
    int n, m;
    cin >> n >> m;
    int r_s, c_s, r_e, c_e;
    cin >> r_s >> c_s >> r_e >> c_e;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            d_s[i][j] = INF;
            d_e[i][j] = INF;
        }
    }
    d_s[r_s][c_s] = 1;
    queue<pair<int, int>> q;
    q.push({r_s, c_s});
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (auto &[dr, dc] : DIR) {
            int rr = r + dr, cc = c + dc;
            if (rr < 1 || rr > n || cc < 1 || cc > m || !g[rr][cc]) {
                continue;
            }
            if (d_s[r][c] + 1 < d_s[rr][cc]) {
                d_s[rr][cc] = d_s[r][c] + 1;
                q.push({rr, cc});
            }
        }
    }
    d_e[r_e][c_e] = 1;
    q.push({r_e, c_e});
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (auto &[dr, dc] : DIR) {
            int rr = r + dr, cc = c + dc;
            if (rr < 1 || rr > n || cc < 1 || cc > m || !g[rr][cc]) {
                continue;
            }
            if (d_e[r][c] + 1 < d_e[rr][cc]) {
                d_e[rr][cc] = d_e[r][c] + 1;
                q.push({rr, cc});
            }
        }
    }
    int cnt = 0, ans = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j]) {
                continue;
            }
            int mn_d_s = INF, mn_d_e = INF;
            for (auto &[dr, dc] : DIR) {
                int ii = i + dr, jj = j + dc;
                if (ii < 1 || ii > n || jj < 1 || jj > m) {
                    continue;
                }
                mn_d_s = min(mn_d_s, d_s[ii][jj]);
                mn_d_e = min(mn_d_e, d_e[ii][jj]);
            }
            if (mn_d_s < INF && mn_d_e < INF) {
                cnt++;
                ans = min(ans, mn_d_s + mn_d_e + 1);
            }
        }
    }
    cout << cnt << '\n' << ans << '\n';
    return 0;
}