/*
    A+B -> AB+
    A*B+C -> AB*C+
    A+B*C+D -> ABC*+D+
    A+B*C/D-E -> ABC*D/+E-
    A+((B*C)/(D-E)) -> 
*/

#include <bits/stdc++.h>

using namespace std;

int get_priority(char c) {
    if (c == '^') {
        return 3;
    }
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}

int main() {
    string infix_expression;
    cin >> infix_expression;
    stack<char> operators;
    for (auto &c : infix_expression) {
        if (c >= 'A' && c <= 'Z') {
            cout << c;
            continue;
        }
        if (c == ')') {
            while (operators.top() != '(') {
                cout << operators.top();
                operators.pop();
            }
            operators.pop();
            continue;
        }
        if (c == '(') {
            operators.push(c);
            continue;
        }
        int priority = get_priority(c);
        while (!operators.empty() && get_priority(operators.top()) >= priority) {
            cout << operators.top();
            operators.pop();
        }
        operators.push(c);
    }
    while (!operators.empty()) {
        cout << operators.top();
        operators.pop();
    }
    return 0;
}