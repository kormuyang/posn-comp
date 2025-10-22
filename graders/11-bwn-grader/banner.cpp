#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    int n, w, s;
    cin >> c >> n >> w >> s;
    int sz = 2 * n + 1;
    for (int i = 0; i <= s; i++) {
        for (int row = 0; row < sz; row++) {
            for (int col = 0; col < w; col++) {
                int patCol = ((col - i) % sz + sz) % sz;
                // (n, n) is the position of the center point
                if (abs(row - n) + abs(patCol - n) <= n) {
                    cout << c;
                } else {
                    cout << '.';
                }
            }
            cout << '\n';
        }
    }
    return 0;
}