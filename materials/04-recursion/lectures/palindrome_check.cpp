#include <bits/stdc++.h>

using namespace std;

// Check whether the input is palindrome or not.

// Input: 13431
// Output: True

// Input: 22332
// Output: False

bool isPalindrome(string s, int left, int right)
{
    if (left >= right)
        return true;
    if (s[left] != s[right])
        return false;
    return isPalindrome(s, left + 1, right - 1);
}

int main()
{
    string s;
    cin >> s;
    cout << (isPalindrome(s, 0, s.length() - 1) ? "True\n" : "False\n");
    return 0;
}