#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000000

vector<bool> isPrime(MAX_N + 1, true);

int main() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX_N; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    int q, n;
    cin >> q >> n;
    while (q--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        vector<bool> chk(MAX_N + 1, false);
        int ans = 0;
        do {
            if (isPrime[stoi(s)] && !chk[stoi(s)]) {
                ++ans;
                chk[stoi(s)] = true;
            }
        } while (next_permutation(s.begin(), s.end()));
        cout << ans << '\n';
    }
    return 0;
}