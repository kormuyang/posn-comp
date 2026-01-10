#include <bits/stdc++.h>

using namespace std;

/*
Test Case #1
Input:
    3 10
    1 3 4
Output:
    3
*/

#define MAX_N 1e6
#define INF 1e9

vector<int> coins(MAX_N);
int n;

// solve(x) = the minimum number of coins required for a sum x
int solve(int x) {
    if (x < 0) {
        return INF;
    }
    if (x == 0) {
        return 0;
    }
    int res = INF;
    for (int i = 0; i < n; i++) {
        res = min(res, solve(x - coins[i]));
    }
    return res + 1;
}

int main() {
    int x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout << solve(x) << '\n';
    return 0;
}