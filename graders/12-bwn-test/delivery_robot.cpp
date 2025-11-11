#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000
vector<vector<int>> grid(MAX_N + 2, vector<int>(MAX_N + 2, 1));
vector<vector<string>> path(MAX_N + 2, vector<string>(MAX_N, string(MAX_N * 2, 'z')));
tuple<int, int, char> DI[4] = {{-1, 0, 'u'}, {1, 0, 'd'}, {0, -1, 'l'}, {0, 1, 'r'}};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }
    int start_r, start_c, final_r, final_c;
    cin >> start_r >> start_c >> final_r >> final_c;
    ++start_r, ++start_c, ++final_r, ++final_c;
    queue<tuple<int, int, string>> q;
    q.push({start_r, start_c, ""});
    path[start_r][start_c] = "";
    while (!q.empty()) {
        auto [x, y, curr] = q.front();
        q.pop();
        if (curr != path[x][y]) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            auto &[xi, yi, ci] = DI[i];
            int tmp_x = x, tmp_y = y;
            while (!grid[tmp_x + xi][tmp_y + yi]) {
                tmp_x += xi, tmp_y += yi;
                if (tmp_x == final_r && tmp_y == final_c) {
                    break;
                }
            }
            if (path[x][y] + ci < path[tmp_x][tmp_y]) {
                path[tmp_x][tmp_y] = path[x][y] + ci;
                q.push({tmp_x, tmp_y, path[tmp_x][tmp_y]});
            }
        }
    }
    if (path[final_r][final_c] != string(MAX_N * 2, 'z')) {
        cout << path[final_r][final_c] << '\n';
    } else {
        cout << "NO\n";
    }
    return 0;
}