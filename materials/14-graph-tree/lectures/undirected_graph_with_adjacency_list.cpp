#include <bits/stdc++.h>

using namespace std;

// Represent Undirected Graph with Adjacency List

/*
Input:
    5 7
    0 1
    0 4
    4 1
    3 4
    1 3
    2 1
    3 2
Output:
    0: 1 4 
    1: 0 4 3 2 
    2: 1 3 
    3: 4 1 2 
    4: 0 1 3
*/

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
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