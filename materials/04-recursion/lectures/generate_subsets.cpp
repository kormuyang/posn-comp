#include <iostream>

using namespace std;

//  Input: ABC
// Output:  C B BC A AC AB ABC

void search(string s, string curr = "", int idx = 0)
{
    if (idx == s.length())
    {
        cout << curr << " ";
        return;
    }
    search(s, curr, idx + 1);
    search(s, curr + s[idx], idx + 1);
    return;
}

int main()
{
    string s;
    cin >> s;
    search(s);
    return 0;
}