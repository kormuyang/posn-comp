/*
    Test Caae #1
    Input:
    5
    3 2 8 15 -8
    17
    Output:
    True

    Test Case #2
    Input:
    4
    2 1 6 3
    6
    Output:
    False

    Test Case #3
    Input:
    4
    5 8 -3 6
    3
    Output:
    True
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, tar;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> tar;
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        int chk = tar - a[i];
        if (s.find(chk) != s.end()) {
            cout << "True\n";
            return 0;
        }
        s.insert(a[i]);
    }
    cout << "False\n";
    return 0;
}