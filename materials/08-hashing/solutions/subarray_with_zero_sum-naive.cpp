/*
Test Case #1
Input:
    5
    4 2 -3 1 6
Output:
    True

Test Case #2
Input:
    5
    4 2 0 1 6
Output:
    True

Test Case #3
Input:
    5
    -3 2 3 1 6
Output:
    False
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    // 0, 1, 2, ... , n - 1
    // [0, 0], [0, 1], [0, 2], ... , [0, n - 1]
    // [1, 1], [1, 2], ... , [1, n - 1]
    // ...
    // [n - 1, n - 1]
    // N(S) = n * (n - 1) / 2

    int n, tar;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            if (sum == 0) {
                cout << "True\n";
                return 0;
            }
        }
    }
    cout << "False\n";
    return 0;
}