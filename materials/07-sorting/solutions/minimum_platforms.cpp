#include <bits/stdc++.h>

// Technique: Sweep line

/*
    Input:
    1 : n where n <= 1*10^5
    n : arr[i] where 0000 <= arr[i] <= 2359
    n : dep[i] where 0000 <= dep[i] <= 2359
    Output:
    1 : minimum platforms
*/

/*
    # 1
    Input:
    6
    900 940 950 1100 1500 1800
    910 1200 1120 1130 1900 2000
    Output:
    3

    # 2
    Input:
    3
    900 1235 1100
    1000 1240 1200
    Output:
    1

    # 3
    Input:
    3
    1000 935 110
    1200 1240 1130
    Output:
    3
*/

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v.push_back({t, 1});
    }
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v.push_back({t + 1, -1});
    }
    sort(v.begin(), v.end());
    int ans = 0, curr = 0;
    for (int i = 0; i < v.size(); i++) {
        curr += v[i].second;
        ans = max(ans, curr);
    }
    cout << ans << '\n';
    return 0;
}