#include <bits/stdc++.h>

using namespace std;

int ans = 0;

void merge(vector<int> &arr, int left, int mid, int right) {
    int n_left = mid - left + 1;
    int n_right = right - mid;

    vector<int> arr_left(n_left), arr_right(n_right);
    for (int i = 0; i < n_left; i++) {
        arr_left[i] = arr[left + i];
    }
    for (int j = 0; j < n_right; j++) {
        arr_right[j] = arr[mid + j + 1];
    }

    int i = 0, j = 0, k = left;
    while (i < n_left && j < n_right) {
        if (arr_left[i] <= arr_right[j]) {
            arr[k] = arr_left[i];
            i++;
        } else {
            arr[k] = arr_right[j];
            j++;
            ans += (n_left - i);
        }
        k++;
    }

    while (i < n_left) {
        arr[k] = arr_left[i];
        i++;
        k++;
    }
    while (j < n_right) {
        arr[k] = arr_right[j];
        j++;
        k++;
    }

    return;
}

void mergeSort(vector<int> &arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
    return;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    mergeSort(v, 0, n - 1);
    cout << ans << '\n';
    return 0;
}
