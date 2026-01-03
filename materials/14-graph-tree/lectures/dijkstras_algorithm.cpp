#include <bits/stdc++.h>

using namespace std;

/*
Dijkstra's Algorithm -> Time Complexity: O((V + E) log V)
Input:
    5 7 0
    0 1 5
    0 2 3
    0 3 7
    1 3 3
    2 3 1
    1 4 2
    3 4 2
Output:
    0 5 3 4 6
*/

#define MAX_N 100000
#define INF 1e9

vector<vector<pair<int, int>>> adj(MAX_N + 1);
vector<int> dist(MAX_N, INF);

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[x] = 0;
    pq.push({0, x});
    while (!pq.empty()) {
        // c -> current cost, u -> current vertex
        auto [c, u] = pq.top();
        pq.pop();
        if (c > dist[u]) {
            continue;
        }
        for (auto &[v, w] : adj[u]) {
            if (c + w < dist[v]) {
                dist[v] = c + w;
                pq.push({c + w, v});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
    return 0;
}