#include <bits/stdc++.h>

using namespace std;

// Score: 90/100

int main() {
    char c;
    int w, p;
    cin >> c >> w >> p;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < w; j++) {
            if (((i % p) + (j % p)) % p == 0) {
                cout << c;
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }
    return 0;
}