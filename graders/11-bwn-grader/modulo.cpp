#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int m = 1;
    for (int i = 0; i < c; i++) {
        m *= 10;
    }
    int ans = 1;
    for (int i = 0; i < b; i++) {
        ans = (ans * a) % m;
    }
    int len = 0;
    for (int i = ans; i > 0; i /= 10) {
        len++;
    }
    for (int i = 0; i < c - len; i++) {
        cout << 0;
    }
    cout << ans << '\n';
    return 0;
}