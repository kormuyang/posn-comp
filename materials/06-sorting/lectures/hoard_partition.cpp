#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &a, int low, int high) {
    int pivot = a[low];
    int i = low - 1, j = high + 1;

    while (true) {
        do {
            i++;
        } while (a[i] < pivot);

        do {
            j--;
        } while (a[j] > pivot);

        if (i >= j) {
            return j;
        }

        swap(a[i], a[j]);
    }
}

int main() {
    vector<int> a = {8, 2, 9, 20, 7, 12, 15, 1, 6};
    int out = partition(a, 0, a.size() - 1);
    cout << out << '\n';
    for (auto &x : a) {
        cout << x << ' ';
    }
    return 0;
}