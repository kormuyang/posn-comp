/*
Input:
    3 + 5
Output:
    3 5 +

Input:
    (120 + 35) * 48
Output:
    120 35 + 48 *

Input:
    75 + (240 - 90) * (16 + 8)
Output:
    75 240 90 - 16 8 + * +

Input:
    (360 + 120) / (24 + 6)
Output:
    360 120 + 24 6 + /
    
Input:
    120 + 35 * (24 ^ 2 - 18) ^ (6 + 14 / 7) - 90
Output:
    120 35 24 2 ^ 18 - 6 14 7 / + ^ * + 90 -
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    string infix_expression;
    getline(cin, infix_expression);
    return 0;
}