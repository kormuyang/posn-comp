#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] - '0') + (b[i] - '0') != 9) {
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << "YES\n";
    } else {
        cout << "NO " << cnt << '\n';
    }
    return 0;
}