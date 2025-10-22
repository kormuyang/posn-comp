#include <bits/stdc++.h>

using namespace std;

int getSum(string s, int len, int i, int ans = 0)
{
    if (i == len)
        return ans;
    return getSum(s, len, i + 1, ans + (s[i] - '0'));
}

int main()
{
    string s;
    cin >> s;
    cout << getSum(s, s.length(), 0) << '\n';
    return 0;
}