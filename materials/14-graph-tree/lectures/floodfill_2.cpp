#include <bits/stdc++.h>

/*
Test Case #1
Input:
5 8
########
#..#...#
####.#.#
#..#...#
########
Output:
########
#11#222#
####2#2#
#33#222#
########
*/

using namespace std;

#define MAX_N 1000

vector<pair<int, int>> DIR = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<string> board(MAX_N);
int n, m;

void bfs(int x_i, int y_i, char c) {
    queue<pair<int, int>> q;
    q.push({x_i, y_i});
    board[x_i][y_i] = c;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < DIR.size(); i++) {
            int x_new = x + DIR[i].first, y_new = y + DIR[i].second;
            if (x_new < 0 || x_new >= n || y_new < 0 || y_new >= m) {
                continue;
            }
            if (board[x_new][y_new] == '.') {
                q.push({x_new, y_new});
                board[x_new][y_new] = c;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '.') {
                cnt++;
                bfs(i, j, '0' + cnt);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << board[i] << '\n';
    }
    return 0;
}