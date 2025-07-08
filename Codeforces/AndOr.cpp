#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(20, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int b = 0; b < 20; ++b) {
            if (a[i] & (1 << b)) {
                cnt[b]++;
            }
        }
    }

    vector<long long> res(n, 0);
    for (int b = 0; b < 20; ++b) {
        for (int i = 0; i < cnt[b]; ++i) {
            res[i] |= (1 << b);
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += 1LL * res[i] * res[i];
    }

    cout << ans << endl;
    return 0;
}
