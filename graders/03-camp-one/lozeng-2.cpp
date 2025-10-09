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
                if (a < h / 2) {
                    for (int b = (h / 2) - a; b <= (h / 2) + a; b++) {
                        out[startRow + a][startCol + b] = c;
                    }
                } else {
                    int gap = a - (h / 2);
                    for (int b = gap; b <= h - 1 - gap; b++) {
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