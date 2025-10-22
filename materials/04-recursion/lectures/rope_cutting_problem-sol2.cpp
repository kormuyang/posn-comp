#include <iostream>

using namespace std;

// Global Variable

// Approach: Buttom Up
int search(int len, int a, int b, int c)
{
    // General Case
    if (n == 0)
    {
        return 0;
    }
    else if (n <= -1)
    {
        return -1;
    }
    int res = max(search(len - a, a, b, c), max(search(len - b, a, b, c), search(len - c, a, b, c)));
    if (res == -1)
    {
        return -1;
    }
    return res + 1;
}

int main()
{
    // Local Variable
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << search(n, a, b, c);
    return 0;
}