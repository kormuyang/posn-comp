#include <bits/stdc++.h>

/*
Test Case #1
Input:
5 8
1 1
########
#..#...#
####.#.#
#..#...#
########
Output:
2
*/

using namespace std;

vector<pair<int, int>> DIR = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
    int n, m, x_i, y_i;
    cin >> n >> m >> x_i >> y_i;
    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    q.push({x_i, y_i});
    vis[x_i][y_i] = true;
    int ans = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < DIR.size(); i++) {
            int x_new = x + DIR[i].first, y_new = y + DIR[i].second;
            if (x_new < 0 || x_new >= n || y_new < 0 || y_new >= m) {
                continue;
            }
            if (board[x_new][y_new] == '.' && !vis[x_new][y_new]) {
                q.push({x_new, y_new});
                vis[x_new][y_new] = true;
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}