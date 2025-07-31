#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, ll>> edges;
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }

    vector<ll> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);
    int x = -1;

    for (int i = 1; i <= n; ++i) {
        x = -1;
        for (auto [a, b, c] : edges) {
            if (dist[a] + c < dist[b]) {
                dist[b] = dist[a] + c;
                parent[b] = a;
                x = b;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    } else {
        for (int i = 0; i < n; ++i)
            x = parent[x];

        vector<int> cycle;
        int v = x;
        do {
            cycle.push_back(v);
            v = parent[v];
        } while (v != x || cycle.size() == 1);
        cycle.push_back(x);
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (int node : cycle) cout << node << " ";
        cout << "\n";
    }

    return 0;
}
