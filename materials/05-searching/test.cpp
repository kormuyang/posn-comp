#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 10;
    vector<int> a(n);
    int ans = -1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, a[i]);
    }

    vector<int> tmp;
    tmp.push_back(50);
    
    return 0;
}