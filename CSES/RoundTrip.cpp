#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
int parent[MAXN];
bool visited[MAXN];
int start = -1, endd = -1;

bool dfs(int node, int par) {
    visited[node] = true;
    for (int neigh : adj[node]) {
        if (neigh == par) continue;
        if (visited[neigh]) {
            start = neigh;
            endd = node;
            return true;
        } else {
            parent[neigh] = node;
            if (dfs(neigh, node)) return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            parent[i] = -1;
            if (dfs(i, -1)) break;
        }
    }

    if (start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(start);
        for (int v = endd; v != start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << "\n";
        for (int x : cycle)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
