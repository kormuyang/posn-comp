#include <bits/stdc++.h>

using namespace std;

int a = 8, b = 9, c = 3;
int ans = 0;

void search(int left, int cnt) {
    if (left < 0) {
        return;
    }
    if (left == 0) {
        ans = max(ans, cnt);
        return;
    }
    search(left - a, cnt + 1);
    search(left - b, cnt + 1);
    search(left - c, cnt + 1);
}

int main() {
    int n = 17;
    search(n, 0);
    cout << ans << '\n';
    return 0;
}