#include <bits/stdc++.h>

using namespace std;

#define MAX_M 10

vector<int> v(MAX_M);
int ans = 0;

int search(int left) {
    if (left == 0) {
        return 0;
    }
    if (left <= -1) {
        return -1;
    }
    int res = -1;
    for (int i = 0; i < v.size(); i++) {
        res = max(res, search(left - v[i]));
    }
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