/*
    Test Case 1:
    17 3
    8 9 3
    -> 4

    Test Case 2:
    10 5
    2 3 4 6 7
    -> 5

    Test Case 3:
    8 4
    3 4 5 7
    -> 2
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX_M 10

vector<int> v(MAX_M);
int ans = 0;

void search(int left, int cnt) {
    if (left < 0) {
        return;
    }
    if (left == 0) {
        ans = max(ans, cnt);
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        search(left - v[i], cnt + 1);
    }
}

int main() {
    int n = 17;
    search(n, 0);
    cout << ans << '\n';
    return 0;
}