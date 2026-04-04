#include <bits/stdc++.h>

using namespace std;

// Time Complexity: O(VlogV + ElogE)

vector<int> parent;
vector<tuple<int, int, int>> edges;

int findParent(int x) {
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unite(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a != b) parent[b] = a;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    parent.resize(n);
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    int ans = 0;
    for(auto &[w, u, v] : edges) {
        if(findParent(u) != findParent(v)) {
            unite(u, v);
            ans += w;
        }
    }
    cout<< ans <<'\n';
    return 0;
}