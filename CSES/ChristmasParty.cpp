#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }

    long long a = 0; 
    long long b = 1; 
    long long c;

    for (int i = 3; i <= n; ++i) {
        c = (1LL * (i - 1) * (a + b) % MOD);
        a = b;
        b = c;
    }

    if (n == 2) cout << b << "\n";
    else cout << c << "\n";

    return 0;
}
