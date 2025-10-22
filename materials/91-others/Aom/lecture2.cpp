#include <bits/stdc++.h>

using namespace std;

void f(int i, int n) {
    if (i > n) {
        return;
    }
    cout << i << '\n';
    f(i + 1, n);
    return;
}

int main() {
    int n = 10;
    f(1, n);
    return 0;
}