#include <bits/stdc++.h>

using namespace std;

#define n 8

int main() {
    // Input
    vector<string> board(n);
    int wCnt = 0, bCnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < n; j++) {
            wCnt += (board[i][j] == 'W' ? 1 : 0);
            bCnt += (board[i][j] == 'B' ? 1 : 0);
        }
    }

    // Process
    int row, col;
    char typ = 'B';
    do {
        cin >> row >> col;
        board[row][col] = typ;
        for (int di = -1; di <= -1; di++) {
            for (int dj = -1; dj <= -1; dj++) {
                if (di == 0 && dj == 0) {
                    continue;
                }
            }
        }
        typ = (typ == 'B' ? 'W' : 'B');
    } while (row != -1);

    // Output
    if (wCnt > bCnt) {
        cout << "white wins\n";
    } else if (wCnt < bCnt) {
        cout << "black wins\n";
    } else {
        cout << "draw\n";
    }
    return 0;
}