#include <bits/stdc++.h>

using namespace std;

// Breath First Search (Queue)

/*
Input:
    3 2
    5 6 0
Output:
    50
    55
    56
    60
    65
    66
*/

int n, m;
vector<string> digits(10);

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> digits[i];
    }
    sort(digits.begin(), digits.begin() + n);
    queue<string> q;
    for (int i = 0; i < n; i++) {
        if (digits[i] != "0") {
            q.push(digits[i]);
        }
    }
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.length() == m) {
            cout << cur << '\n';
            continue;
        }
        for (int i = 0; i < n; i++) {
            q.push(cur + digits[i]);
        }
    }
    return 0;
}