#include <iostream>

using namespace std;

vector<string> PHONE_DIGITS = {"", "", "abc",  "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void search(vector<int> &v, string curr = "", int idx = 0)
{
    if (idx == v.size())
    {
        cout << curr << " ";
        return;
    }
    for (char c : PHONE_DIGITS[v[idx]])
    {
        search(v, curr + c, idx + 1);
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
    {
        cin >> i;
    }
    search(v);
    return 0;
}