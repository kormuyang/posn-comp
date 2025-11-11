#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007
#define MAX_N 1000000

vector<int> FAC(MAX_N + 1, 1), cnt(MAX_N, 1), sz(MAX_N, 1);
vector<vector<int>> adj(MAX_N);

void dfs(int u) {
    if (adj[u].empty()) {
        return;
    }
    for (auto &v : adj[u]) {
        dfs(v);
        sz[u] += sz[v];
    }
    cnt[u] = FAC[sz[u] - 1];
    for (auto &v : adj[u]) {
        cnt[u] = (cnt[u] * cnt[v] / FAC[sz[v]]) % MOD;
    }
}

int32_t main() {
    // Input
    int n, root;
    cin >> n;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if (x == -1) {
            root = i;
            continue;
        }
        adj[x].push_back(i);
    }

    // Set up
    for (int i = 2; i <= MAX_N; ++i) {
        FAC[i] = (FAC[i - 1] * i) % MOD;
    }

    // Process
    dfs(root);

    // Output
    cout << cnt[root] << '\n';
    return 0;
}