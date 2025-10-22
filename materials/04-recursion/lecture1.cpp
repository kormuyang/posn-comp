#include <bits/stdc++.h>

using namespace std;

int f(int x) {
    return x * x;
}

void printAllElements(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

int findMaxElement(vector<int> v) {
    int mx = INT_MIN;
    for (int i = 0; i < v.size(); i++) {
        mx = max(mx, v[i]);
    }
    return mx;
}

int main() {
    vector<int> a = {1, 2, 3, 4}, b = {4, 5}, c = {1, 2, 6};
    int mxA = findMaxElement(a), mxB = findMaxElement(b), mxC = findMaxElement(c);
    cout << mxA + mxB + mxC << '\n';
    return 0;
}