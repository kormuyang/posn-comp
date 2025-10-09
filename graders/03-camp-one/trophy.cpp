#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int h;
    cin >> s >> h;
    string tmp = "";
    for (int i = 0; i < 2 * s.size() * h; i++) {
        tmp += ".";
    }
    vector<string> out(s.size() * h, tmp);

    for (int i = 0; i < s.size(); i++) {
        int startRow = i * h, startCol = i * h;
        for (int j = 0; j < s.size() - i; j++) {
            int col = startCol + j * h * 2;
            for (int a = 0; a < h; a++) {
                for (int b = a; b < h * 2 - a - 1; b++) {
                    out[startRow + a][col + b] = s[i];
                }
            }
        }
    }

    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << '\n';
    }
    return 0;
}