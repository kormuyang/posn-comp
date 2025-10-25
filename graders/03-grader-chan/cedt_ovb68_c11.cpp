#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    // Line 1, 7
    cout << "  ###";
    for (int i = 0; i < s.size(); i++) {
        cout << (i % 2 ? "*#*" : "^#^");
    }
    cout << "###||###";
    for (int i = s.size() - 1; i >= 0; i--) {
        cout << (i % 2 ? "*#*" : "^#^");
    }
    cout << "###\n";

    // Line 2, 6
    cout << " ###";
    for (int i = 0; i < s.size(); i++) {
        cout << (i % 2 ? "#^#" : "#*#");
    }
    cout << "### || ###";
    for (int i = s.size() - 1; i >= 0; i--) {
        cout << (i % 2 ? "#^#" : "#*#");
    }
    cout << "###\n";

    // Line 3, 5
    cout << "###";
    for (int i = 0; i < s.size(); i++) {
        cout << "---";
    }
    cout << "###  ||  ###";
    for (int i = 0; i < s.size(); i++) {
        cout << "---";
    }
    cout << "###\n";

    // Line 4
    cout << "###";
    for (int i = 0; i < s.size(); i++) {
        cout << ' ';
    }
    cout << s;
    for (int i = 0; i < s.size(); i++) {
        cout << ' ';
    }
    cout << "###  ||  ###";
    for (int i = 0; i < s.size(); i++) {
        cout << ' ';
    }
    cout << s;
    for (int i = 0; i < s.size(); i++) {
        cout << ' ';
    }
    cout << "###\n";

    // Line 3, 5
    cout << "###";
    for (int i = 0; i < s.size(); i++) {
        cout << "---";
    }
    cout << "###  ||  ###";
    for (int i = 0; i < s.size(); i++) {
        cout << "---";
    }
    cout << "###\n";

    // Line 2, 6
    cout << " ###";
    for (int i = 0; i < s.size(); i++) {
        cout << (i % 2 ? "#^#" : "#*#");
    }
    cout << "### || ###";
    for (int i = s.size() - 1; i >= 0; i--) {
        cout << (i % 2 ? "#^#" : "#*#");
    }
    cout << "###\n";

    // Line 1, 7
    cout << "  ###";
    for (int i = 0; i < s.size(); i++) {
        cout << (i % 2 ? "*#*" : "^#^");
    }
    cout << "###||###";
    for (int i = s.size() - 1; i >= 0; i--) {
        cout << (i % 2 ? "*#*" : "^#^");
    }
    cout << "###\n";
    return 0;
}