#include <bits/stdc++.h>

using namespace std;

int n;
char x, y;

bool check(string s) {
    int cnt_x = 0, cnt_y = 0;
    for (auto &c : s) {
        if (c == x) {
            ++cnt_x;
        } else {
            ++cnt_y;
        }
        if (cnt_x < cnt_y) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> x >> y;
    string s = "";
    if (x < y) {
        s = string(n, x) + string(n, y);
    } else {
        s = string(n, y) + string(n, x);
    }
    int ans = 0;
    do {
        if (!check(s)) {
            continue;
        }
        int sum = 0;
        for (int i = 0; i < 2 * n; ++i) {
            sum += (s[i] - 'A' + 1) * (i + 1);
        }
        ans += sum;
    } while (next_permutation(s.begin(), s.end()));
    cout << ans << '\n';
    return 0;
}