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

int main() {
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v : adj[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    cout << (dist[d] == INF ? -1 : dist[d]);
    return 0;
}