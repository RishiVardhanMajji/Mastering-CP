#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int &c : coins) cin >> c;

    vector<int> A(x + 1, INF);
    A[0] = 0;

    for (int c : coins) {
        for (int i = c; i <= x; i++) {
            A[i] = min(A[i], A[i - c] + 1);
        }
    }

    cout << (A[x] == INF ? -1 : A[x]) << '\n';
}
