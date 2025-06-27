#include <iostream>

using namespace std;

const long long x = 1e9 + 7;
const long long y = x - 1;

long long modPower(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

int main() {
    int numQueries;
    cin >> numQueries;

    while (numQueries--) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) {
            cout << 1 << '\n';
            continue;
        }

        long long z = modPower(b, c, y);
        long long ans = modPower(a, z, x);

        cout << ans << '\n';
    }

    return 0;
}
