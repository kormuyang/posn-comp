#include <bits/stdc++.h>

using namespace std;

//  Time Complexity: O(N)
// Space Complexity: O(N)

void search(vector<int> survivors, int k, int idx)
{
    if (survivors.size() == 1)
    {
        cout << survivors[0] << '\n';
        return;
    }
    idx = (idx + k) % survivors.size();
    survivors.erase(survivors.begin() + idx);
    search(survivors, k, idx);
    return;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> survivors(n);
    for (int i = 0; i < n; i++)
    {
        survivors[i] = i + 1;
    }
    search(survivors, k - 1, 0);
    return 0;
}