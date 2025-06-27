#include <iostream>
using namespace std;

long long C2(long long x) {
    return (x > 1) ? (x * (x - 1)) / 2 : 0;
}

int main() {
    long long n, m;
    cin >> n >> m;

    long long Kmax = C2(n - m + 1);
    long long a = n / m;
    long long b = n % m;

    long long Kmin = (m - b) * C2(a) + b * C2(a + 1);

    cout << Kmin << " " << Kmax << "\n";
    return 0;
}
