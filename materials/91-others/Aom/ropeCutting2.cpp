#include <bits/stdc++.h>

using namespace std;

// Time Complexity: O(3^N)

int a = 8, b = 9, c = 3;
int ans = 0;

int search(int left) {
    if (left == 0) {
        return 0;
    }
    if (left <= -1) {
        return -1;
    }
    int cntA = search(left - a), cntB = search(left - b), cntC = search(left - c);
    int res = max(cntA, max(cntB, cntC));
    if (res == -1) {
        return -1;
    }
    return res + 1;
}

int main() {
    int n = 17;
    cout << search(n) << '\n';
    return 0;
}