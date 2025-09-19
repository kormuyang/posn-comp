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

void quickSort(vector<int> &a, int low, int high) {
    if (low < high) {
        int pivot = partition(a, low, high);
        quickSort(a, low, pivot);
        quickSort(a, pivot + 1, high);
    }
    return;
}

int main() {
    vector<int> a = {8, 2, 9, 20, 7, 12, 15, 1, 6};
    quickSort(a, 0, a.size() - 1);
    for (auto &x : a) {
        cout << x << ' ';
    }
    return 0;
}