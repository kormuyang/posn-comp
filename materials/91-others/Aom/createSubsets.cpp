#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> v;

void search(int idx, vector<string> res) {
    if (idx == n) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }

    // Don't pick
    search(idx + 1, res);

    // Pick
    res.push_back(v[idx]);
    search(idx + 1, res);
}

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    search(0, vector<string>());
    return 0;
}