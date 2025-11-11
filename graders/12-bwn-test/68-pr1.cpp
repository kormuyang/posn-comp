#include <iostream>

using namespace std;

int main() {
    // Input
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Set up
    vector<int> l_max(n, 0), r_max(n, 0);
    l_max[0] = a[0];
    r_max[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++) {
        l_max[i] = max(l_max[i - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        r_max[i] = max(r_max[i + 1], a[i]);
    }

    // Process
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (min(l_max[i], r_max[i]) > a[i]) {
            ans += min(l_max[i], r_max[i]) - a[i];
        }
    }

    // Output
    cout << ans << '\n';
    return 0;
}