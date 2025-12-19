#include <bits/stdc++.h>

using namespace std;

/*
Test Case #1
Input:
    4 4
    0 1
    0 2
    1 2
    2 3
Output:
    Not Found!

Test Case #2
Input:
    4 5
    0 2
    0 1
    1 2
    2 3
    3 1
Output:
    Found!
*/

#define MAX_N 100000

vector<vector<int>> adj(MAX_N);
vector<bool> vis(MAX_N, false);
vector<bool> recStack(MAX_N, false);

bool isCyclic(int u) {
    vis[u] = true;
    recStack[u] = true;
    for (auto &v : adj[u]) {
        if (!vis[v]) {
            if (isCyclic(v)) {
                return true;
            }
        } else if (recStack[v]) {
            return true;
        }
    }
    recStack[u] = false;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i] && isCyclic(i)) {
            cout << "Found!\n";
            return 0;
        }
    }
    cout << "Not Found!\n";
    return 0;
}