#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF (int)(1e9)

int32_t main() {
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> d(n + 1);
    d[0] = a[0];
    for (int i = 1; i < n; i++) {
        d[i] = a[i] - a[i - 1];
    }
    d[n] = l - a[n - 1];
    int low = 0, high = l;
    while (low < high) {
        int mid = (low + high) / 2, cnt = 0, sum = 0;
        for (int i = 0; i <= n; i++) {
            sum += d[i];
            if (sum > mid) {
                cnt++;
                sum = d[i];
            }
        }
        if (cnt <= k) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << '\n';
    return 0;
}