#include <bits/stdc++.h>

using namespace std;

// DFS Traversal with Recursion

/*
Input:
    6 6 5
    2 3
    5 0
    5 2
    3 1
    4 0
    4 1
Output:
    5 0 2 3 1
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