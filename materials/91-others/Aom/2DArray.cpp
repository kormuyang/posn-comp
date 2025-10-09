#include <bits/stdc++.h>

using namespace std;

// Global Variables
int b[100][100];

void printArray(int a[]) {
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return;
}

int main() {
    int row = 5, col = 5;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> b[i][j];
        }
    }
    return 0;
}