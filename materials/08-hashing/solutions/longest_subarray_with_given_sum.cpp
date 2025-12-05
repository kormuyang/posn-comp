/*
Test Case #1
Input:
    7
    5 8 -4 -4 9 -2 2
    0
Output:
    3

Test Case #2
Input:
    8
    3 1 0 1 8 2 3 6
    5
Output:
    4

Test Case #3
Input:
    4
    8 3 -1 7
    15
Output:
    0
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, tar;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> tar;
    unordered_map<int, int> mp;
    int prefix_sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        prefix_sum += a[i];
        if (prefix_sum == tar) {
            ans = max(ans, i + 1);
        }
        if (mp.find(prefix_sum - tar) != mp.end()) {
            ans = max(ans, i - mp[prefix_sum - tar]);
        }
        mp[prefix_sum] = i;
    }
    cout << ans << '\n';
    return 0;
}