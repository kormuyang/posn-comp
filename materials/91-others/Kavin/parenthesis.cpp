#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        stack<char> st;
        bool chk = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    chk = false;
                    break;
                }
                char c = st.top();
                if ((s[i] == ')' && c != '(') || (s[i] == ']' && c != '[') || (s[i] == '}' && c != '{')) {
                    chk = false;
                    break;
                }
                st.pop();
            }
        }
        if (chk) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}