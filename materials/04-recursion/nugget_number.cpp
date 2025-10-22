#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100

// Global Variable
vector<bool> chk(MAX_N + 1, false);
int n;

// Complete Search
void search(int x) {
    if (x > n) {
        return;
    }
    if (x > 0) {
        chk[x] = true;
    }
    search(x + 6);
    search(x + 9);
    search(x + 20);
}

int main() {
    cin >> n;
    if (n < 6) {
        cout << "no\n";
        return 0;
    }
    search(0);
    for (int i = 6; i <= n; i++) {
        if (chk[i]) {
            cout << i << '\n';
        }
    }
    return 0;
}