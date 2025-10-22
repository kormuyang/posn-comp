#include <bits/stdc++.h>

using namespace std;

int main() {
    // Input
    int n;
    cin >> n;
    vector<char> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Find Unique Characters
    sort(v.begin(), v.end());
    vector<char> c;
    c.push_back(v[0]);
    for (int i = 1; i < n; i++) {
        if (v[i] != v[i - 1]) {
            c.push_back(v[i]);
        }
    }

    // Create Canva
    string tmp = "";
    int sz = c.size() * 2 - 1;
    for (int i = 0; i < sz; i++) {
        tmp += " ";
    }
    vector<string> out(sz, tmp);

    // Edit Canva
    // Edit Upper Diamond
    for (int i = 0; i < c.size(); i++) {
        int startCol = c.size() - 1 - i;
        for (int j = 0; j < i; j++) {
            out[i][startCol + j] = c[j];
        }
        out[i][startCol + i] = c[i];
        int finalCol = c.size() - 1 + i;
        for (int j = 0; j < i; j++) {
            out[i][finalCol - j] = c[j];
        }
    }
    // Edit Lower Diamond
    for (int i = 1; i < c.size(); i++) {
        int row = c.size() - 1 + i, startCol = i, centerCharIdx = c.size() - i - 1;
        for (int j = 0; j < centerCharIdx; j++) {
            out[row][startCol + j] = c[j];
        }
        out[row][startCol + centerCharIdx] = c[centerCharIdx];
        int finalCol = c.size() * 2 - 2 - i;
        for (int j = 0; j < centerCharIdx; j++) {
            out[row][finalCol - j] = c[j];
        }
    }

    // Print Output
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << '\n';
    }
    return 0;
}