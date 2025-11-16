#include <bits/stdc++.h>

using namespace std;

/*
Test Case #1
Input:
    13
    john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john
Output:
    john 4

Test Case #2
Input:
    3
    andy blake clark
Output:
    andy 1
*/

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> mp;
    int mx = 0;
    string ans;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        mp[name]++;
        if (mp[name] > mx) {
            mx = mp[name];
            ans = name;
        } else if (mp[name] == mx) {
            ans = min(ans, name);
        }
    }
    cout << ans << ' ' << mx << '\n';
    return 0;
}