#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100

/*
Input:
4 4
1 0 0 0
1 1 0 1
0 1 0 0
1 1 1 1

Output:
2 0 0 0 
2 2 0 1 
0 2 0 0 
1 2 2 2


Input:
5 5
1 0 1 0 1
1 1 1 0 1
0 1 0 0 0
0 1 1 1 0
0 1 0 0 1

Output:
NO
*/

int row, col;
vector<vector<int>> table(MAX_N, vector<int>(MAX_N));
vector<vector<bool>> vis(MAX_N, vector<bool>(MAX_N, false));

bool search(int y, int x) {
    vis[y][x] = true;
    table[y][x] = 2;
    if (y == row - 1 && x == col - 1) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << table[i][j] << ' ';
            }
            cout << '\n';
        }
        return true;
    }
    if (y + 1 < row && table[y + 1][x] && !vis[y + 1][x] && search(y + 1, x)) {
        return true;
    }
    if (y - 1 >= 0 && table[y - 1][x] && !vis[y - 1][x] && search(y - 1, x)) {
        return true;
    }
    if (x + 1 < col && table[y][x + 1] && !vis[y][x + 1] && search(y, x + 1)) {
        return true;
    }
    if (x - 1 >= 0 && table[y][x - 1] && !vis[y][x - 1] && search(y, x - 1)) {
        return true;
    }
    table[y][x] = 1;
    return false;
}

int main() {
    cin >> row >> col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> table[i][j];
        }
    }
    if (!search(0, 0)) {
        cout << "NO\n";
    }
    return 0;
}