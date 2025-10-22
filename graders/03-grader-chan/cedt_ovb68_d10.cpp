#include <bits/stdc++.h>

using namespace std;

#define MAX_ROW 2
#define MAX_COL 500

vector<vector<bool>> vis(MAX_ROW, vector<bool>(MAX_COL));
vector<string> a(MAX_ROW);
int n, end_row, end_col;

bool isInRange(int row, int col) {
    return (0 <= row && row < MAX_ROW && 0 <= col && col < n);
}

bool search(int row, int col) {
    if (row == end_row && col == end_col) {
        return true;
    }
    if (isInRange(row + 1, col) && a[row + 1][col] != '#' && !vis[row + 1][col]) {
        vis[row + 1][col] = true;
        if (search(row + 1, col)) {
            return true;
        }
    }
    if (isInRange(row - 1, col) && a[row - 1][col] != '#' && !vis[row - 1][col]) {
        vis[row - 1][col] = true;
        if (search(row - 1, col)) {
            return true;
        }
    }
    if (isInRange(row, col + 1) && a[row][col + 1] != '#' && !vis[row][col + 1]) {
        vis[row][col + 1] = true;
        if (search(row, col + 1)) {
            return true;
        }
    }
    if (isInRange(row, col - 1) && a[row][col - 1] != '#' && !vis[row][col - 1]) {
        vis[row][col - 1] = true;
        if (search(row, col - 1)) {
            return true;
        }
    }
    return false;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        cin >> n;
        int start_row, start_col;
        for (int i = 0; i < MAX_ROW; i++) {
            cin >> a[i];
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 'S') {
                    start_row = i;
                    start_col = j;
                } else if (a[i][j] == 'T') {
                    end_row = i;
                    end_col = j;
                }
                vis[i][j] = false;
            }
        }
        vis[start_row][start_col] = true;
        cout << (search(start_row, start_col) ? "Yes\n" : "No\n");
    }
    return 0;
}