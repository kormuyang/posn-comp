#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100

vector<vector<int>> a(MAX_N + 2, vector<int>(MAX_N + 2, 0));
int n, m;
int cnt = 0;

void search(int row, int col) {
    a[row][col] = 0;
    cnt--;
    if (a[row + 1][col]) {
        search(row + 1, col);
    }
    if (a[row - 1][col]) {
        search(row - 1, col);
    }
    if (a[row][col + 1]) {
        search(row, col + 1);
    }
    if (a[row][col - 1]) {
        search(row, col - 1);
    }
}

int main() {
    int q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            cnt += (a[i][j] ? 1 : 0);
        }
    }
    while (q--) {
        int row, col;
        cin >> row >> col;
        if (a[row][col]) {
            search(row, col);
        }
        cout << cnt << '\n';
    }
    return 0;
}