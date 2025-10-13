#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, y, l, t;
    char c;
    cin >> n >> x >> y >> l >> t >> c;

    // Create Canva
    string tmp = "";
    for (int i = 0; i < n; i++) {
        tmp += ".";
    }
    vector<string> out(n, tmp);

    // Edit Canva
    int xNow = x, yNow = y;
    out[yNow][xNow] = c;
    if (t == 0) {
        for (int i = 1; i <= l; i++) {
            // Move Right
            if (i % 4 == 1) {
                for (int j = 1; j <= i; j++) {
                    if (xNow + j < 0 || xNow + j >= n || yNow < 0 || yNow >= n) {
                        continue;
                    }
                    out[yNow][xNow + j] = c;
                }
                xNow += i;
            }
            // Move Down
            else if (i % 4 == 2) {
                for (int j = 1; j <= i; j++) {
                    if (xNow < 0 || xNow >= n || yNow + j < 0 || yNow + j >= n) {
                        continue;
                    }
                    out[yNow + j][xNow] = c;
                }
                yNow += i;
            }
            // Move Left
            else if (i % 4 == 3) {
                for (int j = 1; j <= i; j++) {
                    if (xNow - j < 0 || xNow - j >= n || yNow < 0 || yNow >= n) {
                        continue;
                    }
                    out[yNow][xNow - j] = c;
                }
                xNow -= i;
            } // Move Up
            else {
                for (int j = 1; j <= i; j++) {
                    if (xNow < 0 || xNow >= n || yNow - j < 0 || yNow - j >= n) {
                        continue;
                    }
                    out[yNow - j][xNow] = c;
                }
                yNow -= i;
            }
        }
    } else {
        for (int i = 1; i <= l; i++) {
            // Move Left
            if (i % 4 == 1) {
                for (int j = 1; j <= i; j++) {
                    if (xNow - j < 0 || xNow - j >= n || yNow < 0 || yNow >= n) {
                        continue;
                    }
                    out[yNow][xNow - j] = c;
                }
                xNow -= i;
            }
            // Move Down
            else if (i % 4 == 2) {
                for (int j = 1; j <= i; j++) {
                    if (xNow < 0 || xNow >= n || yNow + j < 0 || yNow + j >= n) {
                        continue;
                    }
                    out[yNow + j][xNow] = c;
                }
                yNow += i;
            }
            // Move Right
            else if (i % 4 == 3) {
                for (int j = 1; j <= i; j++) {
                    if (xNow + j < 0 || xNow + j >= n || yNow < 0 || yNow >= n) {
                        continue;
                    }
                    out[yNow][xNow + j] = c;
                }
                xNow += i;
            } // Move Up
            else {
                for (int j = 1; j <= i; j++) {
                    if (xNow < 0 || xNow >= n || yNow - j < 0 || yNow - j >= n) {
                        continue;
                    }
                    out[yNow - j][xNow] = c;
                }
                yNow -= i;
            }
        }
    }

    // Print Output
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << '\n';
    }
    return 0;
}