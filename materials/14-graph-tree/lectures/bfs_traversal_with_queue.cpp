#include <bits/stdc++.h>

using namespace std;

// BFS Traversal with Queue

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
    0 1 2 3 8 7 5 6 4
*/

#define MAX_N 100000

vector<vector<int>> adj(MAX_N + 1);
vector<bool> vis(MAX_N + 1, false);

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << ' ';
        for (auto &v : adj[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
    cout << '\n';
    return 0;
}