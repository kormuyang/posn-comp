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

#define MAX_N 1e2
#define MAX_VAL 1e6
#define INF 1e9

vector<int> coins(MAX_N);
vector<int> dp(MAX_VAL, -1);
int n;

// solve(x) = the minimum number of coins required for a sum x
int solve(int x) {
    if (x < 0) {
        return INF;
    }
    if (dp[x] != -1) {
        return dp[x];
    }
    dp[x] = INF;
    for (int i = 0; i < n; i++) {
        dp[x] = min(dp[x], 1 + solve(x - coins[i]));
    }
    return dp[x];
}

int main() {
    int x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    dp[0] = 0;
    cout << (solve(x) != INF ? dp[x] : -1) << '\n';
    return 0;
}