#include <iostream>

using namespace std;

// Global Variable
int ans = -1;

// Approach: Top Down
void search(int len, int cnt, int a, int b, int c)
{
    // General Case
    if (len == 0)
    {
        ans = max(ans, cnt);
        return;
    }
    if (len >= a)
        search(len - a, cnt + 1, a, b, c);
    if (len >= b)
        search(len - b, cnt + 1, a, b, c);
    if (len >= c)
        search(len - c, cnt + 1, a, b, c);
    return;
}

int main()
{
    // Local Variable
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    search(n, 0, a, b, c);
    cout << ans << '\n';
    return 0;
}