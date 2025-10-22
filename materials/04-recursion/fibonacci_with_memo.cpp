#include <bits/stdc++.h>

using namespace std;

// f(n) = value of n-th in fibonnaci
// f(n) = f(n - 1) + f(n - 2)

#define MAX_N 100

vector<int> memo(MAX_N + 1, -1);

int f(int n) {
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = f(n - 1) + f(n - 2);
    return memo[n];
}

int main() {
    int n;
    cin >> n;
    memo[0] = 1;
    memo[1] = 1;
    cout << f(n) << '\n';
    return 0;
}