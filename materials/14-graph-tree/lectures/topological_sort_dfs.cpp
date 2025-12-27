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
    5 4 2 3 1 0
*/

#define MAX_N 100000

vector<vector<int>> adj(MAX_N);
vector<bool> vis(MAX_N, false);
stack<int> recStack;

void dfs(int u) {
    vis[u] = true;
    for (auto &v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
    recStack.push(u);
}

void topologicalSort(int n) {
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    while (!recStack.empty()) {
        cout << recStack.top() << ' ';
        recStack.pop();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    topologicalSort(n);
    return 0;
}