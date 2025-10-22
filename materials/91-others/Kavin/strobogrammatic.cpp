#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll low, high, cnt = 0;

void search(string current) {
    if (current != "") {
        if (current.size() > 1 && current[0] == '0') {
            return;
        }
        ll num;
        num = stoll(current);
        if (num > high) {
            return;
        }
        if (num >= low) {
            cnt++;
        }
    }
    if (current != "") {
        search("0" + current + "0");
    }
    search("1" + current + "1");
    search("6" + current + "9");
    search("8" + current + "8");
    search("9" + current + "6");
}

int main() {
    // Input
    cin >> low >> high;

    // Recursion
    search("");
    search("0");
    search("1");
    search("8");

    // Output
    cout << cnt << '\n';
    return 0;
}