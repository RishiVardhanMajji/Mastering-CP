#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    vector<vector<int>> dp(n, vector<int>(m + 2, 0)); 
    if (x[0] == 0) {
        for (int v = 1; v <= m; ++v)
            dp[0][v] = 1;
    } else {
        dp[0][x[0]] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int v = 1; v <= m; ++v) {
            if (x[i] == 0 || x[i] == v) {
                dp[i][v] = ((dp[i - 1][v - 1] + dp[i - 1][v]) % MOD + dp[i - 1][v + 1]) % MOD;
            }
        }
    }

    int result = 0;
    if (x[n - 1] == 0) {
        for (int v = 1; v <= m; ++v)
            result = (result + dp[n - 1][v]) % MOD;
    } else {
        result = dp[n - 1][x[n - 1]];
    }

    cout << result << '\n';
    return 0;
}
