#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000

vector<vector<bool>> board(MAX_N, vector<bool>(MAX_N, false));
vector<vector<int>> dist(MAX_N, vector<int>(MAX_N, INT_MAX));
int n, m;

// x = row, y = col
bool isInRange(int x, int y) { return (0 <= x && x < n && 0 <= y && y < m); }

// x = row, y = col
bool isValid(int x, int y) {
    bool chk = true;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (isInRange(i, j) && !board[i][j]) {
                chk = false;
                break;
            }
        }
    }
    return chk;
}

// x = row, y = col
void search(int x, int y) {
    // Move Down
    if (isInRange(x + 1, y) && board[x + 1][y] && isValid(x + 1, y) &&
        dist[x][y] + 1 < dist[x + 1][y]) {
        dist[x + 1][y] = dist[x][y] + 1;
        search(x + 1, y);
    }
    // Move Up
    if (isInRange(x - 1, y) && board[x - 1][y] && isValid(x - 1, y) &&
        dist[x][y] + 1 < dist[x - 1][y]) {
        dist[x - 1][y] = dist[x][y] + 1;
        search(x - 1, y);
    }
    // Move Right
    if (isInRange(x, y + 1) && board[x][y + 1] && isValid(x, y + 1) &&
        dist[x][y] + 1 < dist[x][y + 1]) {
        dist[x][y + 1] = dist[x][y] + 1;
        search(x, y + 1);
    }
    // Move Left
    if (isInRange(x, y - 1) && board[x][y - 1] && isValid(x, y - 1) &&
        dist[x][y] + 1 < dist[x][y - 1]) {
        dist[x][y - 1] = dist[x][y] + 1;
        search(x, y - 1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            board[i][j] = (x == 1 ? true : false);
        }
    }
    for (int i = 0; i < n; i++) {
        if (board[i][0] && isValid(i, 0)) {
            dist[i][0] = 0;
            search(i, 0);
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dist[i][m - 1]);
    }
    if (ans == INT_MAX) {
        cout << "-1\n";
    } else {
        cout << ans + 1 << '\n';
    }
    return 0;
}