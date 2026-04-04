#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_RANGE 999

int cnt[MAX_RANGE + 1];

bool check(int a, int b) {
    return (a / 100 == b / 100) || ((a / 10) % 10 == (b / 10) % 10) || (a % 10 == b % 10);
}

int32_t main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cnt[(s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0')]++;
    }
    int ans = 0;
    for (int i = 0; i <= MAX_RANGE; i++) {
        if (cnt[i] == 0) {
            continue;
        }
        ans += cnt[i] * (cnt[i] - 1) / 2;
        for (int j = i + 1; j <= MAX_RANGE; j++) {
            if (cnt[j] != 0 && check(i, j)) {
                ans += cnt[i] * cnt[j];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}