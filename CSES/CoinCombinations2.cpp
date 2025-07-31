#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int &c : coins) cin >> c;

    vector<int> A(x + 1, 0);
    A[0] = 1; 

    for (int c : coins) {
        for (int sum = c; sum <= x; sum++) {
            A[sum] = (A[sum] + A[sum - c]) % MOD;
        }
    }

    cout << A[x] << '\n';
}
