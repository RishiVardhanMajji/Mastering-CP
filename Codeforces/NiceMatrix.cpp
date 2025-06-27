#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        long long arr[n][m];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];

        long long ans = 0;

        for (int i = 0; i <= (n - 1) / 2; i++) {
            for (int j = 0; j <= (m - 1) / 2; j++) {
                int i2 = n - 1 - i;
                int j2 = m - 1 - j;

                vector<long long> vals;
                vals.push_back(arr[i][j]);
                if (i != i2) vals.push_back(arr[i2][j]);
                if (j != j2) vals.push_back(arr[i][j2]);
                if (i != i2 && j != j2) vals.push_back(arr[i2][j2]);

                sort(vals.begin(), vals.end());
                long long median = vals[vals.size() / 2]; 
                for (auto v : vals) ans += abs(v - median);
            }
        }

        cout << ans << "\n";
    }
}
