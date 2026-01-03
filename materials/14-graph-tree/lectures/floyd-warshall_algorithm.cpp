#include <bits/stdc++.h>

using namespace std;

/*
Input:
    5 7 0
    0 1 5
    0 2 3
    0 3 7
    1 3 3
    2 3 1
    1 4 2
    3 4 2
*/

#define MAX_N 500
#define INF 1e9

vector<vector<int>> adj(MAX_N, vector<int>(MAX_N, 0));
vector<vector<int>> dist(MAX_N, vector<int>(MAX_N, INF));

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][w] = w;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (adj[i][j]) {
                dist[i][j] = adj[i][j];
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return 0;
}