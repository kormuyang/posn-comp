#include <bits/stdc++.h>

using namespace std;

// Top-down -> Recursion

int f(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    return f(n - 1) + f(n - 2);
}

int main() {
    int n = 10;
    int y = f(n);
    cout << y << '\n';
    return 0;
}