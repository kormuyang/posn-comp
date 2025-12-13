#include <bits/stdc++.h>

using namespace std;

// Represent Weighted Graph with Adjacency List

/*
Input:
    5 7
    0 1 5
    0 4 4
    4 1 3
    3 4 6
    1 3 7
    2 1 3
    3 2 2
Output:
    0: (1, 5) (4, 4) 
    1: (0, 5) (4, 3) (3, 7) (2, 3) 
    2: (1, 3) (3, 2) 
    3: (4, 6) (1, 7) (2, 2) 
    4: (0, 4) (1, 3) (3, 6)
*/

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    // Print Adjacency List
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (auto &[v, w] : adj[i]) {
            cout << '(' << v << ", " << w << ") ";
        }
        cout << '\n';
    }
    return 0;
}