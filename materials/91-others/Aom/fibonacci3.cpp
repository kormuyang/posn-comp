#include <bits/stdc++.h>

using namespace std;

#define MAX_N 50

vector<int> memo(MAX_N + 1, -1);

void f(int n) {
    if (memo[n] != -1) {
        return;
    }
    f(n - 1);
    f(n - 2);
    memo[n] = memo[n - 1] + memo[n - 2];
}

int main() {
    memo[0] = memo[1] = 1;
    int n = 10;
    f(n);
    cout << memo[n] << '\n';
    return 0;
}