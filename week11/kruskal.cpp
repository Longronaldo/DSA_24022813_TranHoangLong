#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

vector<int> parent, sz;

int findSet(int v) {
    if (v == parent[v]) return v;
    return parent[v] = findSet(parent[v]);
}

bool unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (auto &e : edges) cin >> e.u >> e.v >> e.w;

    sort(edges.begin(), edges.end());

    parent.resize(n+1);
    sz.resize(n+1, 1);
    for (int i = 1; i <= n; i++) parent[i] = i;

    int mst_cost = 0;
    vector<Edge> mst;

    for (auto &e : edges) {
        if (unionSet(e.u, e.v)) {
            mst_cost += e.w;
            mst.push_back(e);
        }
    }

    cout << "MST cost = " << mst_cost << "\n";
    cout << "Edges in MST:\n";
    for (auto &e : mst) cout << e.u << " " << e.v << " " << e.w << "\n";

    return 0;
}
