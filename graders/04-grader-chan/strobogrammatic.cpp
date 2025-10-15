#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll l, h, ans = 0;

bool isInRange(ll x) { return (l <= x && x <= h); }

void search(string a, string b) {
    if (stoll(a + b) > h) {
        return;
    }
    if (isInRange(stoll(a + b))) {
        ans++;
    }
    if (isInRange(stoll(a + "0" + b))) {
        ans++;
    }
    if (isInRange(stoll(a + "1" + b))) {
        ans++;
    }
    if (isInRange(stoll(a + "8" + b))) {
        ans++;
    }
    search(a + "0", "0" + b);
    search(a + "1", "1" + b);
    search(a + "6", "9" + b);
    search(a + "8", "8" + b);
    search(a + "9", "6" + b);
}

int main() {
    cin >> l >> h;
    if (isInRange(0)) {
        ans++;
    }
    if (isInRange(1)) {
        ans++;
    }
    if (isInRange(8)) {
        ans++;
    }
    search("1", "1");
    search("6", "9");
    search("8", "8");
    search("9", "6");
    cout << ans << '\n';
    return 0;
}