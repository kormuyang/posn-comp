#include <bits/stdc++.h>

using namespace std;

/*
Test Case #1
Input:
    6 6
    5 0
    5 2
    2 3
    3 1
    4 0
    4 1
Output:
    4 5 0 2 3 1
*/

#define MAX_N 100000

vector<vector<int>> adj(MAX_N);
vector<int> in_degree(MAX_N, 0);

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << ' ';
        for (int &v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }
    return 0;
}