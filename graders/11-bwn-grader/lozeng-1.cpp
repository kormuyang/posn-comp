#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    int h, n;
    cin >> c >> h >> n;
    string tmp = "";
    for (int i = 0; i < h * n; i++) {
        tmp += '.';
    }
    vector<string> out(h * n, tmp);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int startRow = i * h, startCol = j * h;
            for (int a = 0; a < h; a++) {
                for (int b = 0; b < h; b++) {
                    if (a + b >= h / 2 && a - b <= h / 2 && b - a <= h / 2 && a + b < 3 * h / 2) {
                        out[startRow + a][startCol + b] = c;
                    }
                }
            }
        }
    }

    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << '\n';
    }
    return 0;
}