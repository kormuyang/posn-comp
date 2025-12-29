#include <bits/stdc++.h>

using namespace std;

// Basic Operations
// 1. Insert
// 2. Access
// 3. Delete
// 4. Search

// Stack, Queue -> Don't have iterator

int main() {
    queue<int> q;

    // 1. Insert -> O(1)
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    // 2. Access -> O(1)
    int number = q.front(); // number = 10

    // 3. Delete -> O(1)
    q.pop();

    // 4. Search -> O(N) (For Traversal)
    while (!q.empty()) {
        cout << q.front() << '\n';
        q.pop();
    }

    return 0;
}