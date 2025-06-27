#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 2000005;

vector<long long> factorial(MAX), inverse_factorial(MAX);

long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2) result = result * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return result;
}

void prepare() {
    factorial[0] = 1;
    for (int i = 1; i < MAX; i++)
        factorial[i] = factorial[i - 1] * i % MOD;

    inverse_factorial[MAX - 1] = power(factorial[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--)
        inverse_factorial[i] = inverse_factorial[i + 1] * (i + 1) % MOD;
}

long long combination(int total, int choose) {
    if (choose < 0 || choose > total) return 0;
    return factorial[total] * inverse_factorial[choose] % MOD * inverse_factorial[total - choose] % MOD;
}

int main() {
    int children, apples;
    cin >> children >> apples;

    prepare();

    cout << combination(children + apples - 1, apples) << "\n";
    return 0;
}
