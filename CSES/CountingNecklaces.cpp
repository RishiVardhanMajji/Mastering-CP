#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp) {
        if (exp % 2) res = res * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int g = gcd(i, n);
        sum = (sum + power(m, g, MOD)) % MOD;
    }

   
    long long inv_n = power(n, MOD - 2, MOD); 
    long long result = sum * inv_n % MOD;

    cout << result << "\n";
    return 0;
}
