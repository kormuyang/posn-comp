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
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
        cnt++;
    }
    cout << (cnt == n ? "Not Found!\n" : "Found!\n");
    return 0;
}