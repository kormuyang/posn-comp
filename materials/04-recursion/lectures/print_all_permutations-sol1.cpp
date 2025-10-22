#include <bits/stdc++.h>

//  Time Complexity O(N!)
// Space Complexity O(N)

using namespace std;

void search(string s, vector<bool> used, int idx, string curr)
{
    if (idx == s.size())
    {
        cout << curr << '\n';
        return;
    }
    for (int i = 0 ; i < s.size(); i++)
    {
        if (!used[i])
        {
            used[i] = trsue;
            search(s, used, idx + 1, curr + s[i]);
            used[i] = false;
        }
    }
    return;
}

int main()
{
    string s;
    cin >> s;
    vector<bool> used(s.size(), false);
    search(s, used, 0, "");
    return 0;
}