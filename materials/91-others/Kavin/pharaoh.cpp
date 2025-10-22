#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.size();

    // Create Canva
    string tmp = "";
    for (int i = 0; i < len * 2 * len - 1; i++) {
        tmp += ".";
    }
    vector<string> out(len * 2 * len, tmp);

    // Edit Canva
    for (int i = 0; i < len; i++) {
        int startCol = i * len * 2, startRow = i * len;
        for (int j = 0; j < len - i; j++) {
            int row = startRow + j * len * 2;
            for (int a = 0; a < len; a++) {
                for (int b = 0; b < len - a; b++) {
                    out[row + b + a][startCol + a * 2] = s[b];
                }
                int finalRow = row + len * 2 - a - 2;
                for (int b = 0; b < len - a - 1; b++) {
                    out[finalRow - b][startCol + a * 2] = s[b];
                }
            }
        }
    }

    // Print Canva
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << '\n';
    }
    return 0;
}