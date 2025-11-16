#include <bits/stdc++.h>

/*
    Input:
    1 : n        where n <= 10^5
    n : start[i] where 0 <= start[i] <= 10^6
    n : end[i]   where 0 <= end[i] <= 10^6
    Output:
    1 : minimum platforms
*/

/*
    # 1
    Input:
    4
    1 2 6 9
    3 4 8 10
    Output:
    (1, 4) (6, 8) (9, 10)

    # 2
    Input:
    4
    6 1 2 4
    8 9 4 7
    Output:
    (1, 9)
*/

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
    }
    sort(v.begin(), v.end());

    // ..., a_i, a_i+1, a_i+2, ...
    // (1, 3), (2, 4), (6, 8), (9, 10)

    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (v[i].first <= v[idx].second) {
            v[idx].first = min(v[idx].first, v[i].first);
            v[idx].second = max(v[idx].second, v[i].second);
        } else {
            idx++;
            v[idx] = v[i];
        }
    }
    for (int i = 0; i <= idx; i++) {
        cout << "(" << v[i].first << ", " << v[i].second << ") ";
    }
    return 0;
}