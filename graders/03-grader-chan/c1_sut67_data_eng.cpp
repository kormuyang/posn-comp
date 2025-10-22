#include <bits/stdc++.h>

using namespace std;

string convertToBinary(int x) {
    string out = "";
    while (x) {
        out = (x % 2 == 0 ? "0" : "1") + out;
        x /= 2;
    }
    return out;
}

bool comp(string a, string b) { return (a + b) > (b + a); }

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i] = convertToBinary(x);
    }
    sort(v.begin(), v.end(), comp);
    string tmp = "";
    for (int i = 0; i < n; i++) {
        tmp += v[i];
    }
    int ans = 0;
    for (int i = 0; i < tmp.size(); i++) {
        ans *= 2;
        ans += tmp[i] - '0';
    }
    cout << ans << '\n';
    return 0;
}