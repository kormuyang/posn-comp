#include <bits/stdc++.h>

using namespace std;

#define MAX_M 1000
#define MAX_N 500

vector<vector<int>> dp(MAX_M, vector<int>(MAX_N, -1));

int solve(int w, int n) {
    if (w == 0 || n == 0) {
        return 0;
    }
    if (dp[w][n] != -1) {
        return dp[w][n];
    }
    return 0;
}

int main() {
    int w, n;
    return 0;
}