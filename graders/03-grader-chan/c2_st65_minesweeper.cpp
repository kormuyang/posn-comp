#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000

vector<vector<bool>> a(MAX_N + 2, vector<bool>(MAX_N + 2, false));
vector<vector<int>> dist(MAX_N + 2, vector<int>(MAX_N + 2, INT_MAX));

int main() {
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            a[i][j] = (x == 1);
            if (!a[i][j]) {
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; j++) {
                a[i][j] = false;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i][1]) {
            q.push({i, 1});
            dist[i][1] = 1;
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (y == m) {
            cout << dist[x][y] << '\n';
            return 0;
        }
        if (a[x + 1][y] && dist[x][y] + 1 < dist[x + 1][y]) {
            q.push({x + 1, y});
            dist[x + 1][y] = dist[x][y] + 1;
        }
        if (a[x - 1][y] && dist[x][y] + 1 < dist[x - 1][y]) {
            q.push({x - 1, y});
            dist[x - 1][y] = dist[x][y] + 1;
        }
        if (a[x][y + 1] && dist[x][y] + 1 < dist[x][y + 1]) {
            q.push({x, y + 1});
            dist[x][y + 1] = dist[x][y] + 1;
        }
        if (a[x][y - 1] && dist[x][y] + 1 < dist[x][y - 1]) {
            q.push({x, y - 1});
            dist[x][y - 1] = dist[x][y] + 1;
        }
    }
    cout << "-1\n";
    return 0;
}