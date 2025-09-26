#include <bits/stdc++.h>

using namespace std;

// Bottom-up -> For-loop

int main() {
    int n = 10;
    vector<int> f(n + 1);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n] << '\n';
    return 0;
}