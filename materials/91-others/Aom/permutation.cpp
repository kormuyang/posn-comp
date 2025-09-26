#include <bits/stdc++.h>

using namespace std;

string s = "ABC";

void search(string res, vector<bool> chk) {
    if (res.size() == s.size()) {
        cout << res << '\n';
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (!chk[i]) {
            chk[i] = true;
            search(res + s[i], chk);
            chk[i] = false;
        }
    }
}

int main() {
    search("", vector<bool>(s.size(), false));
    return 0;
}