#include <bits/stdc++.h>

using namespace std;

int main() {
    int r;
    cin >> r;
    int sz = 2 * r + 1;

    // Create Canva
    string tmp = "";
    for (int i = 0; i < sz; i++) {
        tmp += ".";
    }
    vector<string> out(sz, tmp);

    // Edit Canva
    int xCenter = r, yCenter = r;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if ((i - yCenter) * (i - yCenter) + (j - xCenter) * (j - xCenter) >= r * r &&
                (i - yCenter) * (i - yCenter) + (j - xCenter) * (j - xCenter) < (r + 1) * (r + 1)) {
                out[i][j] = '*';
            } else if ((i - yCenter) * (i - yCenter) + (j - xCenter) * (j - xCenter) >=
                           (r - 3) * (r - 3) &&
                       (i - yCenter) * (i - yCenter) + (j - xCenter) * (j - xCenter) <
                           (r - 2) * (r - 2)) {
                out[i][j] = '*';
            } else if (i == j &&
                       (i - yCenter) * (i - yCenter) + (j - xCenter) * (j - xCenter) < r * r) {
                out[i][j] = '#';
            } else if (i + j == 2 * r &&
                       (i - yCenter) * (i - yCenter) + (j - xCenter) * (j - xCenter) < r * r) {
                out[i][j] = '#';
            } else if (i == r) {
                out[i][j] = '-';
            } else if (j == r) {
                out[i][j] = '|';
            }
        }
    }

    // Print Output
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << '\n';
    }
    return 0;
}