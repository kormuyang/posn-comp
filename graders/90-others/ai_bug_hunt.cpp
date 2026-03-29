#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> s;
    s[a[0]]++;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; (1 << j) <= a[i]; j++) {
            int tar = a[i] ^ (1 << j);
            if (s.find(tar) != s.end()) {
                ans += s[tar];
            }
        }
        s[a[i]]++;
    }
    cout << ans << '\n';
    return 0;
}