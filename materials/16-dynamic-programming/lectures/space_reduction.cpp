#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100

vector<vector<int>> sum(2, vector<int>(MAX_N + 2, 0));
vector<vector<int>> val(MAX_N + 2, vector<int>(MAX_N + 2, 0));

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> val[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        int curr = i % 2, prev = (i - 1) % 2;
        for (int j = 1; j <= m; j++) {
            sum[curr][j] = val[i][j] + max(sum[prev][j], sum[curr][j - 1]);
        }
    }
    cout << sum[n % 2][m] << '\n';
    return 0;
}