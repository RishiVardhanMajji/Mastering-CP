#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<int> w(n);
    for (int i = 0; i < n; ++i) cin >> w[i];

    int N = 1 << n;
    vector<pair<int, long long>> dp(N, {INF, 0});
    dp[0] = {1, 0}; 

    for (int mask = 0; mask < N; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) {
                int new_mask = mask | (1 << i);
                auto [rides, weight] = dp[mask];
                if (weight + w[i] <= x) {
                    dp[new_mask] = min(dp[new_mask], {rides, weight + w[i]});
                } else {
                    dp[new_mask] = min(dp[new_mask], {rides + 1, w[i]});
                }
            }
        }
    }

    cout << dp[N - 1].first << '\n';
    return 0;
}
