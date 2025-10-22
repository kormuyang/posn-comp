#include <bits/stdc++.h>

using namespace std;

// Recusive Function
void printHello(int n) {
    if (n == 0) {
        return;
    }
    cout << "Hello\n";
    printHello(n - 1);
}

int main() {
    int n;
    cin >> n;
    printHello(n);
    return 0;
}