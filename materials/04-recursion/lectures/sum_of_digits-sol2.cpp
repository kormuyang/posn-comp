#include <bits/stdc++.h>

using namespace std;

int getSum(string s, int len, int i)
{
    if (i == len)
        return 0;
    return getSum(s, len, i + 1) + (s[i] - '0');
}

int main()
{
    string s;
    cin >> s;
    cout << getSum(s, s.length(), 0) << '\n';
    return 0;
}