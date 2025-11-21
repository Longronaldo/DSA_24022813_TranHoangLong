#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // thêm cạnh u -> v (đồ thị vô hướng)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS sử dụng đệ quy
    void DFS_util(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v])
                DFS_util(v, visited);
        }
    }

    // Hàm gọi DFS
    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS từ đỉnh " << start << ": ";
        DFS_util(start, visited);
        cout << endl;
    }

    // BFS dùng queue
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS từ đỉnh " << start << ": ";

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);

    // thêm các cạnh
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    g.DFS(0);
    g.BFS(0);

    return 0;
}
