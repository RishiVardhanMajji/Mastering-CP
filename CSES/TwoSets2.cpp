#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    int total = n * (n + 1) / 2;

    if (total % 2 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    int target = total / 2;

    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int num = 1; num <= n; ++num) {
        for (int i = target; i >= num; --i) {
            dp[i] = (dp[i] + dp[i - num]) % MOD;
        }
    }

    int inv2 = (MOD + 1) / 2;
    cout << (1LL * dp[target] * inv2 % MOD) << '\n';

    return 0;
}
