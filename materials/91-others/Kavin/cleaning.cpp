#include <bits/stdc++.h>

using namespace std;

#define MAX_N 500

vector<vector<int>> arr(MAX_N + 2, vector<int>(MAX_N + 2));

int main() {
    // Input
    int n;
    cin >> n;
    string s;
    cin >> s;
    string cur = "";
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '[' && s[i] != ']' && s[i] != ',') {
            cur += s[i];
        } else if (cur != "") {
            arr[(cnt / n) + 1][(cnt % n) + 1] = stoi(cur);
            cnt++;
            cur = "";
        }
    }

    // Process
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] > 0) {
                ans += 2;
            }
            // Up
            if (arr[i - 1][j] < arr[i][j]) {
                ans += arr[i][j] - arr[i - 1][j];
            }
            // Down
            if (arr[i + 1][j] < arr[i][j]) {
                ans += arr[i][j] - arr[i + 1][j];
            }
            // Left
            if (arr[i][j - 1] < arr[i][j]) {
                ans += arr[i][j] - arr[i][j - 1];
            }
            // Right
            if (arr[i][j + 1] < arr[i][j]) {
                ans += arr[i][j] - arr[i][j + 1];
            }
        }
    }

    // Output
    cout << ans << '\n';
    return 0;
}