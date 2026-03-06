#include <bits/stdc++.h>

using namespace std;

// DFS Traversal with Recursion

/*
Input:
    9 10 0
    0 1
    0 2
    0 3
    3 5
    3 6
    5 4
    4 6
    2 8
    2 7
    7 8
Output:
    0 1 2 8 7 3 5 4 6
*/

#define MAX_N 100000

vector<vector<int>> adj(MAX_N);
vector<bool> vis(MAX_N, false); // visited

void dfs(int u) {
    vis[u] = true;
    cout << u << ' ';
    for (auto &v : adj[u]) {
        if (vis[v]) {
            continue;
        }
        dfs(v);
    }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    dfs(s);
    cout << '\n';
    return 0;
}