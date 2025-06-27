#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long coins[n];

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins, coins + n);
    long long smallest_unreachable = 1;

    for (int i = 0; i < n; i++) {
        if (coins[i] > smallest_unreachable) {
            break;
        }
        smallest_unreachable += coins[i];
    }
    cout << smallest_unreachable;
    return 0;
}
