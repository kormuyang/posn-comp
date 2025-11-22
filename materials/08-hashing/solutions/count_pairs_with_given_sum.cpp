/*
    Test Caae #1
    Input:
    5
    1 5 7 -1 5
    6
    Output:
    3 // (1, 5), (7, -1), (1, 5)

    Test Case #2
    Input:
    4
    1 1 1 1
    2
    Output:
    6

    Test Case #3
    Input:
    5
    10 12 10 15 -1
    125
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
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int chk = tar - a[i];
        if (mp.find(chk) != mp.end()) {
            ans += mp[chk];
        }
        mp[a[i]]++;
    }
    cout << ans << '\n';
    return 0;
}