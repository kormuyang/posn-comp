#include <bits/stdc++.h>

using namespace std;

#define MAX_N 20

int main() {
    // Input
    int n, m;
    string s;
    cin >> n >> m >> s;

    // Create Board
    string tmp = "";
    for (int i = 0; i < m; i++) {
        tmp += ". ";
    }
    vector<string> out(n, tmp);

    // Print the Initial Board
    out[0][0] = 'e';
    for (int i = 0; i < n; i++) {
        cout << out[i] << '\n';
    }
    cout << "--------------------\n";

    // Edit and Print all Boards
    int row = 0, col = 0;
    for (int i = 0; i < s.size(); i++) {
        // Edit Board
        out[row][col] = '.';
        if (s[i] == 'w') {
            row = max(0, row - 1);
        } else if (s[i] == 's') {
            row = min(n - 1, row + 1);
        } else if (s[i] == 'a') {
            col = max(0, col - 2);
        } else {
            col = min((m - 1) * 2, col + 2);
        }
        out[row][col] = 'e';

        // Print Board
        for (int j = 0; j < n; j++) {
            cout << out[j] << '\n';
        }
        cout << "--------------------\n";
    }
    return 0;
}