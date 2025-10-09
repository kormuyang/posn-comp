#include <iostream>

using namespace std;

int main() {
    string s;
    int h;
    cin >> s >> h;
    int sz = 2 * h + 1;
    string tmp = "";
    for (int i = 0; i < (sz - 2) * s.size() + 2; i++) {
        tmp += ".";
    }
    vector<string> out(sz, tmp);

    for (int i = 0; i < s.size(); i++) {
        int start = i * (sz - 2);
        for (int j = 0; j < sz; j++) {
            if (h - j >= 0) {
                out[h - j][start + j] = s[i];
                out[h + j][start + j] = s[i];
            } else {
                out[j - h][start + j] = s[i];
                out[sz - (j - h) - 1][start + j] = s[i];
            }
        }
    }

    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << '\n';
    }
    return 0;
}