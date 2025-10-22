#include <bits/stdc++.h>

using namespace std;

int f(int x) { return x + 1; }

void printAllElements(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int y;
    y = f(10);

    vector<int> a(10), b(10), c(10);
    printAllElements(a);
    printAllElements(b);
    printAllElements(c);
    return 0;
}