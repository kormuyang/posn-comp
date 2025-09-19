#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100

vector<string> board(MAX_N + 1);
vector<vector<bool>> chk(MAX_N + 1, vector<bool>(MAX_N + 1, false));
int n, ans = 0;

void search(int x, int y) {
    bool bomb = false;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i < 1 || i > n || j < 1 || j > n) {
                continue;
            }
            if (board[i][j] == '*') {
                ans++;
                bomb = true;
            }
        }
    }
    if (bomb) {
        return;
    }
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i < 1 || i > n || j < 1 || j > n) {
                continue;
            }
            if (!chk[i][j]) {
                chk[i][j] = true;
                search(i, j);
            }
        }
    }
    return;
}

int main() {
    cin >> n;
    int x, y;
    cin >> x >> y;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            board[i][j] = s[j - 1];
        }
    }
    chk[y][x] = true;
    search(y, x);
    cout << ans << '\n';
    return 0;
}
