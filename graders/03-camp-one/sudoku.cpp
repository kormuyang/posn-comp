#include <bits/stdc++.h>

using namespace std;

#define n 9

vector<string> board(n);

int main() {
    int q;
    cin >> q;
    while (q--) {
        vector<pair<int, int>> pos;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> board[i];
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '0') {
                    pos.push_back({i, j});
                }
            }
        }
        for (int i = 0; i < pos.size(); i++) {
            int row = pos[i].first, col = pos[i].second;
            vector<bool> chk(n + 1, false);
            int tmp = (col + 1) * 10 + (row + 1);
            for (int i = 0; i < n; i++) {
                chk[board[i][col] - '0'] = true;
            }
            for (int i = 0; i < n; i++) {
                chk[board[row][i] - '0'] = true;
            }
            for (int i = 1; i <= n; i++) {
                if (!chk[i]) {
                    tmp = tmp * 10 + i;
                    break;
                }
            }
            ans += tmp;
        }
        cout << ans << '\n';
    }
    return 0;
}