#include <bits/stdc++.h>

using namespace std;

// Global Variables
int n;

// Print from 1 to N
void printNum(int i) {
    if (i > n) {
        return;
    }
    cout << i << '\n';
    printNum(i + 1);
}

int main() {
    cin >> n;
    printNum(1);
    return 0;
}