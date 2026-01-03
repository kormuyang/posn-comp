#include <bits/stdc++.h>

using namespace std;

/*
Bellman-Ford Algorithm -> Time Complexity: O(V * E)
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

vector<tuple<int, int, int>> edges;
vector<int> dist(MAX_N, INF);

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        edges.push_back({v, u, w});
    }
    dist[x] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto &[u, v, w] : edges) {
            dist[v] = min(dist[v], dist[u] + w);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
    return 0;
}