  
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

    for (int i = 1; i <= x; i++) {
        for (int c : coins) {
            if (i - c >= 0) {
                A[i] = (A[i] + A[i - c]) % MOD;
            }
        }
    }

    cout << A[x] << '\n';
}
