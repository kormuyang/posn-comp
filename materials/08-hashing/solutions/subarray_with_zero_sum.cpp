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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_set<int> s;
    int prefix_sum = 0;
    for (int i = 0; i < n; i++) {
        prefix_sum += a[i];
        if (prefix_sum == 0 || s.find(prefix_sum) != s.end()) {
            cout << "True\n";
            return 0;
        }
        s.insert(prefix_sum);
    }
    cout << "False\n";
    return 0;
}