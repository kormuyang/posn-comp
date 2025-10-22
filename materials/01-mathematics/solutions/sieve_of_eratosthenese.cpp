#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool is_prime[n + 1];
    for (int i = 0; i <= n; i++)
        is_prime[i] = true;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (j % i == 0)
                    is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
            cout << i << ' ';
    }
    cout << '\n';
    return 0;
}
