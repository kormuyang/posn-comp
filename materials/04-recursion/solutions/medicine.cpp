// Input
// 5 10
// 2 3 4 6 7

// Output
// 8
// 2 2 2 2 2 
// 2 2 2 4 
// 2 2 3 3 
// 2 2 6 
// 2 4 4 
// 3 3 4 
// 3 7 
// 4 6

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> res;

void search(vector<int> v, vector<int> curr, int idx, int sum)
{
    if (sum == m)
    {
        res.push_back(curr);
        return;
    }
    for (int i = idx; i < n; i++)
    {
        if (sum + v[i] <= m)
        {
            curr.push_back(v[i]);
            search(v, curr, i, sum + v[i]);
            curr.pop_back();
        }
    }
    return;
}

int main()
{
    cin >> n >> m;
    vector<int> v(n);
    for (int &x : v)
    {
        cin >> x;
    }
    search(v, {}, 0, 0);
    cout << res.size() << '\n';
    for (auto &x : res)
    {
        for (int &y : x)
        {
            cout << y << ' ';
        }
        cout << '\n';
    }
    return 0;
}