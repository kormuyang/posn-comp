#include <bits/stdc++.h>

using namespace std;

// Time Complexity: O(VlogV + ElogV)

#define MAX_N (int)(1e5)
#define INF (int)(1e9)

vector<pair<int, int>> adj[MAX_N];
vector<int> dist(MAX_N, INF);
vector<bool> vis(MAX_N, false);

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    int ans = 0;
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        ans += d;
        for (auto &[v, w] : adj[u]) {
            if (!vis[v] && w < dist[v]) {
                dist[v] = w;
                pq.push({w, v});
            }
        }
    }
    cout << ans << '\n';
    return 0;
}