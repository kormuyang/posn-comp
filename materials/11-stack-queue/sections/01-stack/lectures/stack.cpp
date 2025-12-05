#include <bits/stdc++.h>

using namespace std;

// Basic Operations
// 1. Insert
// 2. Access
// 3. Delete
// 4. Search

// Stack, Queue -> Don't have iterator

int main() {
    stack<int> st;

    // 1. Insert -> O(1)
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    // 2. Access -> O(1)
    int number = st.top(); // number = 30

    // 3. Delete -> O(1)
    st.pop();

    // 4. Search -> O(N) (For Traversal)
    while (!st.empty()) {
        cout << st.top() << '\n';
        st.pop();
    }

    return 0;
}