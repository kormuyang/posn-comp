/*
Test Case #1
Input:
    7
    15 2 4 8 9 5 10
    23
Output:
    1 4

Test Case #2
Input:
    6
    1 10 4 0 3 5
    7
Output:
    2 4

Test Case #3
Input:
    3
    1 4 -3
    0
Output:
    -1 -1
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
    int prefix_sum = 0;
    for (int i = 0; i < n; i++) {
        prefix_sum += a[i];
        if (prefix_sum == tar) {
            cout << "0 " << i << '\n';
            return 0;
        }
        if (mp.find(prefix_sum - tar) != mp.end()) {
            cout << mp[prefix_sum - tar] + 1 << ' ' << i << '\n';
            return 0;
        }
        mp[prefix_sum] = i;
    }
    cout << "-1 -1\n";
    return 0;
}