#include <bits/stdc++.h>
using namespace std;
int main() {
    char a[100];
    scanf("%s", a);
    int h;
    cin >> h;
    int k = h * 2 - 1;
    int po = 1;
    int ok = 0;
    int d = 0;
    for (int i = 0; i < strlen(a) * h; i++) {
        for (int j = 0; j < i; j++) {
            cout << ".";
        }
        for (int e = 0; e < strlen(a) - ok; e++) {
            for (int j = 0; j < k; j++) {
                cout << a[d];
            }
            if (e < strlen(a) - 1 - ok) {
                for (int j = 0; j < po; j++) {
                    cout << ".";
                }
            } else {
                for (int j = 0; j <= i; j++) {
                    cout << ".";
                }
            }
        }
        k -= 2;
        po += 2;
        if ((i + 1) % 3 == 0) {
            d++;
            k = h * 2 - 1;
            po = 1;
            ok++;
        }
        cout << "\n";
    }
} // nokchrome
