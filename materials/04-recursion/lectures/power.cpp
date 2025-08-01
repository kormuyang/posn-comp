#include <iostream>

using namespace std;

int f(int b, int p)
{
    if (p == 0)
        return 1;
    return b * f(b, p - 1);
}

int main()
{
    // find value of 4^3, which is equal 64
    cout << f(4, 3) << '\n';
    return 0;
}