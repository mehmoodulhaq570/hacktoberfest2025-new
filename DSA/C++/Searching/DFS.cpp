#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// ------------------------------
// Recursive DFS
// ------------------------------
void dfs_recursive(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs_recursive(neighbor, adj, visited);
        }
    }
}

// ------------------------------
// Iterative DFS (using stack)
// ------------------------------
void dfs_iterative(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int node = s.top();
        s.pop();
        cout << node << " ";

        // Traverse all neighbors (reverse order to match recursion output)
        for (int i = adj[node].size() - 1; i >= 0; --i) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                s.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

// ------------------------------
// Main Function
// ------------------------------
int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<vector<int>> adj(vertices);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    vector<bool> visited(vertices, false);

    cout << "\nRecursive DFS starting from node 0: ";
    dfs_recursive(0, adj, visited);

    // Reset visited for iterative DFS
    fill(visited.begin(), visited.end(), false);

    cout << "\nIterative DFS starting from node 0: ";
    dfs_iterative(0, adj, visited);

    cout << endl;
    return 0;
}
