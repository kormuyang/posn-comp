#include <bits/stdc++.h>

using namespace std;

//  Time Complexity: O(N)
// Space Complexity: O(1)

int search(int n, int k)
{
    if (n == 1)
    {
        return 1;
    }
    return ((search(n - 1, k) + (k - 1)) % n) + 1;

    // n = 5, k = 2
    // [1, 2, 3, 4, 5]
    // [1, 3, 4, 5]
    // [1, 3, 5]
    // [3, 5]
    // [3]

    // bottom-up
    // search(1, 2) = 1
    // search(2, 2) = ((1 + 1) % 2) + 1 = 1
    // search(3, 2) = ((1 + 1) % 3) + 1 = 3
    // search(4, 2) = ((3 + 1) % 4) + 1 = 1
    // search(5, 2) = ((1 + 1) % 5) + 1 = 3
}

int main()
{
    int n, k;
    cin >> n >> k;

    // search(n, k) returns the position of the survivor.

    cout << search(n, k) << '\n';
    return 0;
}