#include <bits/stdc++.h>

using namespace std;

/*
Input:
    8 10 0 7
    2 1
    1 0
    0 3
    3 7
    3 4
    4 7
    7 6
    6 4
    4 5
    5 6
Output:
    2
*/

#define MAX_N 100000
#define INF 1e9

vector<vector<int>> adj(MAX_N);
vector<int> dist(MAX_N, INF);

int d;

void dfs(int u) {
    if (u == d) {
        return;
    }
    for (int i = 0; i < adj[u].size(); i++) {
        // dist[x] = shortest path from source to x
        if (dist[u] + 1 < dist[adj[u][i]]) {
            dist[adj[u][i]] = dist[u] + 1;
            dfs(adj[u][i]);
        }
    }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s >> d;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dist[s] = 0;
    dfs(s);
    cout << (dist[d] == INF ? -1 : dist[d]) << '\n';
    return 0;
}