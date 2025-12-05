/*
    Test Caae #1
    Input:
    [{()}]
    Output:
    True

    Test Case #2
    Input:
    ([{[]]}{)
    Output:
    False

    Test Case #3
    Input:
    [()()]{}
    Output:
    True
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    for (char &c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (st.empty()) {
            cout << "False\n";
            return 0;
        } else if ((st.top() == '(' && c != ')') || (st.top() == '{' && c != '}') || (st.top() == '[' && c != ']')) {
            cout << "False\n";
            return 0;
        } else {
            st.pop();
        }
    }
    cout << (st.empty() ? "True\n" : "False\n");
    return 0;
}