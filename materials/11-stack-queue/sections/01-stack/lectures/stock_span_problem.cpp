/*
Test Case #1
Input:
    4
    100 80 90 120
Output:
    1 1 2 4

Test Case #2
Input:
    6
    10 4 5 90 120 80
Output:
    1 1 2 4 5 1
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && v[st.top()] <= v[i]) {
            st.pop();
        }
        cout << (st.empty() ? i + 1 : i - st.top()) << ' ';
        st.push(i);
    }
    return 0;
}