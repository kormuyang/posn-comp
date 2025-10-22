#include <bits/stdc++.h>

using namespace std;

// Find the sum of all digits.

// Input: 12
// Output: 3

// Input: 13431
// Output: 12

int getSum(int n)
{
    if (n == 0)
        return 0;
    return getSum(n / 10) + (n % 10);
}

int main()
{
    int n;
    cin >> n;
    cout << getSum(n) << '\n';
    return 0;
}