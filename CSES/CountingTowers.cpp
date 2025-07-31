#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    vector<int> ns(t);
    int max_n = 0;

    for (int i = 0; i < t; ++i) {
        cin >> ns[i];
        max_n = max(max_n, ns[i]);
    }

    vector<long long> connected(max_n + 1);
    vector<long long> nconnected(max_n + 1);
    vector<int> answers(max_n + 1);

    connected[1] = 1;
    nconnected[1] = 1;
    answers[1] = 2;

    for (int i = 2; i <= max_n; ++i) {
        connected[i] = (2LL * connected[i - 1] + nconnected[i - 1]) % MOD;
        nconnected[i] = (4LL * nconnected[i - 1] + connected[i - 1]) % MOD;
        answers[i] = (connected[i] + nconnected[i]) % MOD;
    }

    for (int n : ns) {
        cout << answers[n] << '\n';
    }
}
