#include <iostream>

using namespace std;

// Find the sum of natural numbers from 1 to N.

// input: 5
// output: 15

// input: 10
// output: 55

int getSum(int n, int ans = 0)
{
    if (n == 0)
        return ans;
    return getSum(n - 1, ans + n);
}

int main()
{
    int n;
    cin >> n;
    cout << getSum(n) << '\n';
    return 0;
}