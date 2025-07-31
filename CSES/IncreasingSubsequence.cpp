#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];

    vector<int> dp;

    for (int val : x) {
        auto it = lower_bound(dp.begin(), dp.end(), val);
        if (it == dp.end()) {
            dp.push_back(val);
        } else {
            *it = val;
        }
    }

    cout << dp.size() << '\n';

    return 0;
}
