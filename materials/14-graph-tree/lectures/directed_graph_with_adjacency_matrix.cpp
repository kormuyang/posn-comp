#include <bits/stdc++.h>

using namespace std;

// Represent Directed Graph with Adjacency Matrix

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
    0: 0 0 0 0 0 0 
    1: 0 0 0 0 0 0 
    2: 0 0 0 1 0 0 
    3: 0 1 0 0 0 0 
    4: 1 1 0 0 0 0 
    5: 1 0 1 0 0 0
*/

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
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