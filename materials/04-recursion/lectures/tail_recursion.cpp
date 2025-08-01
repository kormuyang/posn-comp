#include <iostream>

using namespace std;

// Tail Recursion
int f(int b, int p, int ans = 1)
{
    if (p == 0)
        return ans;
    return f(b, p - 1, ans * b);
}

int main()
{
    // Find the value of 4^3, which is equal 64.
    cout << f(4, 3) << '\n';
    return 0;
}