#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    int h;
    cin >> c >> h;
    int sz = 2 * h + 1;
    string tmp;
    for (int i = 0; i < sz; i++) {
        tmp += ".";
    }
    vector<string> out(sz, tmp);

    for (int i = 0; i <= h; i++) {
        for (int j = h - i; j <= h + i; j++) {
            out[i][j] = c;
        }
    }
    for (int i = h + 1; i < sz; i++) {
        for (int j = i - h; j < sz - (i - h); j++) {
            out[i][j] = c;
        }
    }

    for (int i = 0; i < sz; i++) {
        out[i][i] = '+';
        out[i][h] = '+';
        out[h][i] = '+';
        out[i][sz - i - 1] = '+';
    }

    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << '\n';
    }
    return 0;
}