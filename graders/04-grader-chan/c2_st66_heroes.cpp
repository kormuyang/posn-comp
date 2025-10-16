#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> heroes(n);
    for (int i = 0; i < n; i++) {
        cin >> heroes[i];
    }
    vector<pair<int, ll>> monsters(m);
    for (int i = 0; i < m; i++) {
        cin >> monsters[i].first >> monsters[i].second;
    }
    sort(monsters.begin(), monsters.end());
    for (int i = 1; i < m; i++) {
        monsters[i].second += monsters[i - 1].second;
    }
    for (int i = 0; i < n; i++) {
        // (ll) 0 = this 0 is long long, not int
        auto it = upper_bound(monsters.begin(), monsters.end(), make_pair(heroes[i] + 1, (ll) 0));
        if (it == monsters.begin()) {
            cout << "0\n";
            continue;
        }
        it--;
        cout << (*it).second << '\n';
    }
    return 0;
}