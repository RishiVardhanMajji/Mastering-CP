
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 1;

vector<long long> fact(MAX), inv_fact(MAX);

long long mod_pow(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2) res = res * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return res;
}

void precompute() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < MAX; ++i)
        fact[i] = fact[i - 1] * i % MOD;

    inv_fact[MAX - 1] = mod_pow(fact[MAX - 1], MOD - 2, MOD);
    for (int i = MAX - 2; i >= 1; --i)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

long long binomial(int a, int b) {
    if (b < 0 || b > a) return 0;
    return fact[a] * inv_fact[b] % MOD * inv_fact[a - b] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    precompute();

    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << binomial(a, b) << "\n";
    }
}

/*#include <iostream>

using namespace std;

void bincoef(int a,int b){
    const long long x= 1e9 +7;
    double val=1.0;
    for(long long i=1;i<=a-b;i++){
        val=val*(i+b)/i;
    }
    long long c=val;
    cout << c << "\n";
    cout<< c%x;

}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a,b;
        bincoef(a,b);
        cout << "\n";
    }
}
    */