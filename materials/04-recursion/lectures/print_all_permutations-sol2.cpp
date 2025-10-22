#include <bits/stdc++.h>

//  Time Complexity O(N!)
// Space Complexity O(1)

using namespace std;

void search(string s, int idx)
{
    if (idx == s.size() - 1)
    {
        cout << s << '\n';
        return;
    }
    for (int i = idx; i < s.size(); i++)
    {
        swap(s[idx], s[i]);
        search(s, idx + 1);
        swap(s[idx], s[i]);
    }
    return;
}

int main()
{
    string s;
    cin >> s;
    search(s, 0);
    return 0;
}