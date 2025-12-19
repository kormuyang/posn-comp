#include <bits/stdc++.h>

using namespace std;

/*
Test Case #1
Input:
    3 2
    0 1
    1 2
Output:
    Not Found!

Test Case #2
Input:
    5 5
    1 0
    0 2
    2 1
    0 3
    3 4
Output:
    Found!
*/

#define MAX_N 100000

vector<vector<int>> adj(MAX_N);
vector<bool> vis(MAX_N, false);

bool isCyclic(int u, int parent) {
    vis[u] = true;
    for (auto &v : adj[u]) {
        if (!vis[v]) {
            if (isCyclic(v, u)) {
                return true;
            }
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i] && isCyclic(i, -1)) {
            cout << "Found!\n";
            return 0;
        }
    }
    cout << "Not Found!\b";
    return 0;
}