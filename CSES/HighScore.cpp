#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    struct Edge { int a, b; ll w; };
    vector<Edge> edges(m);
    vector<vector<int>> adj(n + 1), rev(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        ll x;
        cin >> a >> b >> x;
        edges[i] = {a, b, -x};
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 1; i < n; ++i) {
        for (auto [a, b, w] : edges) {
            if (dist[a] < INF && dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
            }
        }
    }

    vector<bool> affected(n + 1);
    for (auto [a, b, w] : edges) {
        if (dist[a] < INF && dist[a] + w < dist[b]) {
            affected[b] = true;
        }
    }

    queue<int> q;
    vector<bool> reachable(n + 1);
    q.push(n);
    reachable[n] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : rev[u]) {
            if (!reachable[v]) {
                reachable[v] = true;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (affected[i] && reachable[i]) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << -dist[n] << '\n';
    return 0;
}
