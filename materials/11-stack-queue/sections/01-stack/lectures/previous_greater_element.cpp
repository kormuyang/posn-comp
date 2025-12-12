/*
Test Case #1
Input:
    7
    10 4 2 20 40 12 30
Output:
    -1 10 4 -1 -1 40 40

Test Case #2
Input:
    4
    40 30 20 10
Output:
    -1 -1 -1 -1
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() <= v[i]) {
            st.pop();
        }
        cout << (st.empty() ? -1 : st.top()) << ' ';
        st.push(v[i]);
    }
    return 0;
}