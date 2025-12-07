#include <bits/stdc++.h>

using namespace std;

// Represent Undirected Graph with Adjacency Matrix

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
    0: 0 1 0 0 1
    1: 1 0 1 1 1
    2: 0 1 0 1 0
    3: 0 1 1 0 1
    4: 1 1 0 1 0
*/

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    // Print Adjacency Matrix
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}