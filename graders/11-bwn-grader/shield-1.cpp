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

    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (i == j || i + j == sz - 1 || i == h || j == h) {
                out[i][j] = '+';
            } else if (i + j >= h && i - j <= h && j - i <= h && i + j <= 3 * h) {
                out[i][j] = c;
            }
        }
    }

    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << '\n';
    }
    return 0;
}