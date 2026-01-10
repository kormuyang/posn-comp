/*
Test Case #1
Input:
    4
    1 3
    2 5
    3 9
    6 8
Output:
    2
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> events(n);
    for (int i = 0; i < n; i++) {
        cin >> events[i].second >> events[i].first;
    }
    sort(events.begin(), events.end());
    int ans = 0;
    int cur = 0;
    for (auto &[r, l] : events) {
        if (l > cur) {
            ans++;
            cur = r;
        }
    }
    cout << ans << '\n';
    return 0;
}