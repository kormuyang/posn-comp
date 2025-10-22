#include <bits/stdc++.h>

using namespace std;

// f(n) = value of n-th in fibonnaci
// f(n) = f(n - 1) + f(n - 2)

int f(int n) {
    // cout << "start f(" << n << ")\n";
    if (n == 0 || n == 1) {
        return 1;
    }
    int a = f(n - 1), b = f(n - 2);
    // cout << "end f(" << n << ")\n";
    return a + b;
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << '\n';
    return 0;
}