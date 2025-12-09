#include <bits/stdc++.h>

using namespace std;

int score = 0;
char h[10][10];

void mairulawtae(int x, int y, char t) {
    if (h[x][y + 1] == t) {
        score++;
        h[x][y] = '-';
        mairulawtae(x, y + 1, t);
    }
    if (h[x + 1][y] == t) {
        score++;
        h[x][y] = '-';
        mairulawtae(x + 1, y, t);
    }
    if (h[x - 1][y] == t) {
        score++;
        h[x][y] = '-';
        mairulawtae(x - 1, y, t);
    }
    if (h[x][y - 1] == t) {
        score++;
        h[x][y] = '-';
        mairulawtae(x, y - 1, t);
    }
    if (h[x][y] == t) {
        score++;
    }
    h[x][y] = '-';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a;
    int b;
    cin >> a >> b;
    char t;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> h[i][j];
        }
    }
    int q;
    cin >> q;
    int x, y;
    char r;
    char copy;

    // for (int i = 0; i < q; i++) {
    //     cin >> y >> x;
    //     cin >> r;
    //     if (r == 'L') {
    //         if (h[x - 1][y] != '-' || h[x][y] < 'A' || h[x][y] > 'Z') {
    //             score--;
    //         } else {

    //             copy = h[x - 1][y];
    //             h[x - 1][y] = h[x][y];
    //             h[x][y] = copy;

    //             x--;
    //             copy = h[x][y];
    //             h[x][y] = '-';
    //             cout << copy;
    //             while (h[x][y + 1] == '-') {
    //                 y++;
    //                 cout << y;
    //             }
    //             cout << h[x][y + 1];
    //             cout << x;
    //             h[x][y] = copy;
    //             mairulawtae(x, y, h[x][y]);
    //         }

    //     } else {

    //         if (h[x + 1][y] != '-' || h[x][y] < 'A' || h[x][y] > 'Z') {
    //             score--;
    //         } else {
    //             copy = h[x + 1][y];
    //             h[x + 1][y] = h[x][y];
    //             h[x][y] = copy;

    //             x++;
    //             copy = h[x][y];
    //             h[x][y] = '-';
    //             while (h[x][y + 1] == '-') {
    //                 y++;
    //             }
    //             h[x][y] = copy;

    //             mairulawtae(x, y, h[x][y]);
    //         }
    //     }

    //     for (int i = 0; i < a; i++) {
    //         for (int j = 0; j < b; j++) {
    //             cout << h[j][i];
    //         }
    //         cout << "\n";
    //     }
    // }

    // cout << score * 5 << "\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << h[i][j];
        }
        cout << "\n";
    }
    return 0;
}