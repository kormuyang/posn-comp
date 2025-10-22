#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> pos(q);
    bool outOfRange = false;
    for (int i = 0; i < q; i++) {
        cin >> pos[i].first >> pos[i].second;
        if (pos[i].first < 0 || pos[i].second >= n || pos[i].second < 0 || pos[i].second >= n) {
            outOfRange = true;
        }
    }
    if (outOfRange) {
        cout << "Out of range\n";
        return 0;
    }

    // Create Canva
    string tmp = "";
    for (int i = 0; i < n; i++) {
        tmp += "_";
    }
    vector<string> out(n, tmp);

    // Edit Canva
    out[pos[0].first][pos[0].second] = 'A';
    for (int i = 1; i < q; i++) {
        // Move Right
        if (pos[i].second > pos[i - 1].second) {
            for (int j = pos[i - 1].second + 1; j < pos[i].second; j++) {
                out[pos[i - 1].first][j] = '>';
            }
        }
        // Move Left
        else if (pos[i].second < pos[i - 1].second) {
            for (int j = pos[i - 1].second - 1; j > pos[i].second; j--) {
                out[pos[i - 1].first][j] = '<';
            }
        }
        // Move Down
        if (pos[i].first > pos[i - 1].first) {
            for (int j = pos[i - 1].first; j < pos[i].first; j++) {
                out[j][pos[i].second] = 'v';
            }
        }
        // Move Up
        else if (pos[i].first < pos[i - 1].first) {
            for (int j = pos[i - 1].first; j > pos[i].first; j--) {
                out[j][pos[i].second] = '^';
            }
        }
        out[pos[i].first][pos[i].second] = 'A' + i;
    }

    // Print Output
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << '\n';
    }
    return 0;
}