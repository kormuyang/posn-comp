#include <bits/stdc++.h>

using namespace std;

#define MAX_N 750

vector<string> v(MAX_N);
vector<vector<bool>> chk(MAX_N, vector<bool>(MAX_N, false));
int n, m;

bool isValid(int row, int col) {
    return 0 <= row && row < n && 0 <= col && col < m;
}

int bfs(int row, int col) {
    queue<pair<int, int>> q;
    q.push({row, col});
    chk[row][col] = true;
    int cnt = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        cnt++;
        for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; j++) {
                if (isValid(i, j) && v[i][j] == '.' && !chk[i][j]) {
                    chk[i][j] = true;
                    q.push({i, j});
                }
            }
        }
    }
    return cnt;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '.' && !chk[i][j]) {
                ans = max(ans, bfs(i, j));
            }
        }
    }
    cout << ans << '\n';
    return 0;
}