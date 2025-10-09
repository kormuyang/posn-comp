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
    // Print Upper Diamond
    for (int i = 0; i < c.size(); i++) {
        int startCol = c.size() - 1 - i, centerCharIndex = i;
        for (int j = 0; j < startCol; j++) {
            cout << ' ';
        }
        for (int j = 0; j < centerCharIndex; j++) {
            cout << c[j];
        }
        cout << c[centerCharIndex];
        for (int j = centerCharIndex - 1; j >= 0; j--) {
            cout << c[j];
        }
        for (int j = 0; j < startCol; j++) {
            cout << ' ';
        }
        cout << '\n';
    }
    // Print Lower Diamond
    for (int i = 1; i < c.size(); i++) {
        int startCol = i, centerCharIndex = c.size() - 1 - i;
        for (int j = 0; j < startCol; j++) {
            cout << ' ';
        }
        for (int j = 0; j < centerCharIndex; j++) {
            cout << c[j];
        }
        cout << c[centerCharIndex];
        for (int j = centerCharIndex - 1; j >= 0; j--) {
            cout << c[j];
        }
        for (int j = 0; j < startCol; j++) {
            cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}