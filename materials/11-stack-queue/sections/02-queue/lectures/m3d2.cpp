/*
Test Case #1
Input:
    27
Output:
    1 * 3 * 3 * 3

Test Case #2
Input:
    13
Output:
    1 * 3 * 3 * 3 / 2

Test Case #3
Input:
    36
Output:
    1 * 3 * 3 / 2 * 3 * 3
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> prv(n * 3, -1);
    queue<int> q;
    q.push(1);
    prv[1] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur * 3 < n * 3 && prv[cur * 3] == -1) {
            prv[cur * 3] = cur;
            q.push(cur * 3);
        }
        if (prv[cur / 2] == -1) {
            prv[cur / 2] = cur;
            q.push(cur / 2);
        }
    }
    if (prv[n] == -1) {
        cout << "-1\n";
        return 0;
    }
    string ans = "";
    while (n != 1) {
        if (prv[n] * 3 == n) {
            ans = " * 3" + ans;
        } else {
            ans = " / 2" + ans;
        }
        n = prv[n];
    }
    ans = '1' + ans;
    cout << ans << '\n';
    return 0;
}