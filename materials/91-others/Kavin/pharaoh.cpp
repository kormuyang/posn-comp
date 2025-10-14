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
    for (int idx = 0; idx < len; idx++) {
        int startCol = idx * len * 2, startRow = idx * len;
        for (int cnt = 0; cnt < len - idx; cnt++) {
            int row = startRow + cnt * len * 2;
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < len - i; j++) {
                    out[row + j + i][startCol + i * 2] = s[j];
                }
                int finalRow = row + len * 2 - i - 2;
                for (int j = 0; j < len - i - 1; j++) {
                    out[finalRow - j][startCol + i * 2] = s[j];
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