#include <bits/stdc++.h>

using namespace std;

// Macro
#define MAX_N 10

// Global Variable
vector<int> v(MAX_N);
vector<vector<int>> res;
int n, k, cnt = 0;

void search(int sum, int idx, vector<int> curr) {
    if (sum == k) {
        cnt++;
        res.push_back(curr);
        return;
    } else if (sum > k || idx == n) {
        return;
    }
    curr.push_back(v[idx]);
    search(sum + v[idx], idx, curr);
    curr.pop_back();
    search(sum, idx + 1, curr);
    return;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> v[i];
    search(0, 0, {});
    cout << cnt << '\n';
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}