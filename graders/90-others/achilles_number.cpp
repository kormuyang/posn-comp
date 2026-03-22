#include <bits/stdc++.h>

using namespace std;

#define int long long 

int gcd(int m, int n) {
    if (n == 0) {
        return m;
    }
    return gcd(n, m % n);
}

bool isPerfectPower(int x) {
    if (x == 1) {
        return true;
    }
    int common_gcd = 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i != 0) {
            continue;
        }
        int cnt = 0;
        while (x % i == 0) {
            cnt++;
            x /= i;
        }
        if (common_gcd == 0) {
            common_gcd = cnt;
        } else {
            common_gcd = gcd(common_gcd, cnt);
        }
    }
    if (x > 1) {
        return false;
    }
    return (common_gcd > 1);
}

int32_t main() {
    int l, r;
    cin >> l >> r;
    set<int> powerful_numbers;
    for (int i = 1; ; i++) {
        int i_3 = i * i * i;
        if (i_3 > r) {
            break;
        }
        for (int j = 1; ; j++) {
            int j_2 = j * j;
            if (i_3 * j_2 > r) {
                break;
            }
            if (i_3 * j_2 >= l) {
                powerful_numbers.insert(i_3 * j_2);
            }
        }
    }
    int ans = 0;
    for (auto &x : powerful_numbers) {
        ans += (isPerfectPower(x) ? 0 : 1);
    }
    cout << ans << '\n';
    return 0;
}