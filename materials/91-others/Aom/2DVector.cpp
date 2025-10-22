#include <bits/stdc++.h>

using namespace std;

// Global Variables
vector<int> a(100, 0);
vector<vector<int>> b(50, vector<int>(100)); // 50 x 100

int main() {
    int row = 5, col = 5;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> b[i][j];
        }
    }
    return 0;
}