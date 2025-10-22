#include <bits/stdc++.h>

using namespace std;

int main() {
    // Input
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int lower, upper;
    cin >> lower >> upper;

    // Set up
    int ans = 0, prefix = 0;
    multiset<int> ms;
    ms.insert(0);

    // Process
    for (int i = 0; i < n; i++) {
        prefix += a[i];
        // Count [prefix - upper, prefix - lower]
        auto it1 = ms.lower_bound(prefix - upper);
        auto it2 = ms.upper_bound(prefix - lower);
        ans += distance(it1, it2);
        ms.insert(prefix);
    }

    // Output
    cout << ans << '\n';
    return 0;
}