#include <bits/stdc++.h>

using namespace std;

// Represent Directed Graph with Adjacency List

/*
Input:
    6 6
    2 3
    5 0
    5 2
    3 1
    4 0
    4 1
Output:
    0: 
    1: 
    2: 3 
    3: 1 
    4: 0 1 
    5: 0 2
*/

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    // Print Adjacency List
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (auto &v : adj[i]) {
            cout << v << ' ';
        }
        cout << '\n';
    }
    return 0;
}