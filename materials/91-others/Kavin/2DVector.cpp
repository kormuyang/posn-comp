#include <iostream>
#include <vector>

using namespace std;

int main() {
    // STL -> standard template library
    vector<int> a(10, 5);
    vector<vector<int>> b(4, a);
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            cout << '(' << i << ", " << j << ") ";
        }
        cout << '\n';
    }
    return 0;
}