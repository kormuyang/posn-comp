#include <bits/stdc++.h>

using namespace std;

// Depth First Search (Recursion)

int n, m;
vector<char> digits(10);

void dfs(string cur) {
    if (cur.length() == m) {
        cout << cur << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        dfs(cur + digits[i]);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> digits[i];
    }
    sort(digits.begin(), digits.begin() + n);
    dfs("");
    return 0;
}