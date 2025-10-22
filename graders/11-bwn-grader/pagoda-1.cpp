#include <bits/stdc++.h>

using namespace std;

// Reference: Trophy

int main() {
    // Input
    char c;
    int h, n;
    cin >> c >> h >> n;

    // Create Canva
    string tmp = "";
    for (int i = 0; i < 2 * h * n; i++) {
        tmp += '.';
    }
    vector<string> out(h * n, tmp);

    // Edit Canva
    for (int i = 0; i < n; i++) {
        int startRow = i * h, startCol = i * h;
        for (int j = 0; j < n - i; j++) {
            int col = startCol + 2 * h * j;
            for (int p = 0; p < h; p++) {
                for (int q = p; q < 2 * h - p - 1; q++) {
                    out[startRow + p][col + q] = c;
                }
            }
        }
    }

    // Print Output
    for (int i = out.size() - 1; i >= 0; i--) {
        cout << out[i] << '\n';
    }
}