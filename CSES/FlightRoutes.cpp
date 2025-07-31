#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.emplace(0, 1);

    vector<int> count(n + 1, 0);
    vector<ll> result;

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();

        count[u]++;
        if (u == n) result.push_back(dist);
        if (count[u] > k) continue;

        for (auto [v, cost] : adj[u]) {
            pq.emplace(dist + cost, v);
        }
    }

    for (ll x : result) cout << x << ' ';
    cout << '\n';

    return 0;
}
