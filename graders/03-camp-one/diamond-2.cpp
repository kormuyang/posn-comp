#include <bits/stdc++.h>

using namespace std;

int main() {
    // Input
    int n;
    cin >> n;
    vector<char> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Find Unique Characters
    sort(v.begin(), v.end());
    vector<char> c;
    c.push_back(v[0]);
    for (int i = 1; i < n; i++) {
        if (v[i] != v[i - 1]) {
            c.push_back(v[i]);
        }
    }

    // Output
    // Create Canva
    string tmp = "";
    int sz = c.size() * 2 - 1;
    for (int i = 0; i < sz; i++) {
        tmp += " ";
    }
    vector<string> out(sz, tmp);
    // Edit Upper Diamond
    return 0;
}