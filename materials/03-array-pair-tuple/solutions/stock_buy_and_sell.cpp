#include <iostream>

using namespace std;

// 7
// 100 180 260 310 40 535 695
// output: 865

int main()
{
    int n; cin >> n;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            ans += (a[i] - a[i - 1]);
        }
    }

    cout << ans << '\n';
    return 0;
}