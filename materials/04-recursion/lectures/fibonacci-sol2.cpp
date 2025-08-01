#include <iostream>

using namespace std;

// MEMO
vector<int> memo(101, -1);

int f(int n)
{
    if (memo[n] != -1)
        return memo[n];
    memo[n] = f(n - 1) + f(n - 2);
    return memo[n];
}

int main()
{
    memo[1] = 1;
    memo[2] = 1;
    cout << f(45) << '\n';
    return 0;
}