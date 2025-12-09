#include <bits/stdc++.h>

using namespace std;

#define MAX_N 17

vector<vector<int>> v(MAX_N + 2, vector<int>(MAX_N + 2, 0));
vector<pair<int, int>> DI = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int search(int x, int y) {
    bool chk = false;
    if (v[x][y + 1] == v[x][y] && v[x + 1][y] == v[x][y]) {
        chk = true;
    } else if (v[x + 1][y] == v[x][y] && v[x + 1][y - 1] == v[x][y]) {
        chk = true;
    } else if (v[x][y + 1] == v[x][y] && v[x + 1][y + 1] == v[x][y]) {
        chk = true;
    } else if (v[x + 1][y] == v[x][y] && v[x + 1][y + 1] == v[x][y]) {
        chk = true;
    }
    int cnt = 0, tar = v[x][y];
    queue<pair<int, int>> q;
    q.push({x, y});
    v[x][y] = 0;
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        cnt++;
        for (auto &[di, dj] : DI) {
            if (v[i + di][j + dj] == tar) {
                q.push({i + di, j + dj});
                v[i + di][j + dj] = 0;
            }
        }
    }
    return chk && (cnt == 3);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!v[i][j]) {
                continue;
            }
            ans += search(i, j);
        }
    }
    cout << ans << '\n';
    return 0;
}