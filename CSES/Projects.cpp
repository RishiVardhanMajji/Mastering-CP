#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Project {
    ll start, end, profit;
};

int main() {
    
    int n;
    cin >> n;
    vector<Project> projects(n);

    for (int i = 0; i < n; ++i) {
        cin >> projects[i].start >> projects[i].end >> projects[i].profit;
    }

    sort(projects.begin(), projects.end(), [](const Project &a, const Project &b) {
        return a.end < b.end;
    });

    vector<ll> dp(n);
    vector<ll> ends(n);
    for (int i = 0; i < n; ++i) ends[i] = projects[i].end;

    for (int i = 0; i < n; ++i) {
        ll include = projects[i].profit;
        int last = lower_bound(ends.begin(), ends.end(), projects[i].start) - ends.begin() - 1;
        if (last >= 0) include += dp[last];
        dp[i] = max(i == 0 ? 0LL : dp[i-1], include);
    }

    cout << dp[n - 1] << '\n';
    return 0;
}
