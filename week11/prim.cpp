#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> visited(n+1, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, 1}); 
    int mst_cost = 0;

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = 1;
        mst_cost += w;

        for (auto &p : adj[u]) {
            int v = p.first, weight = p.second;
            if (!visited[v])
                pq.push({weight, v});
        }
    }

    cout << "MST cost = " << mst_cost << "\n";

    return 0;
}
