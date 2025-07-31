#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MAX_SUM = 100000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i)
        cin >> coins[i];

    bitset<MAX_SUM + 1> possible;
    possible[0] = 1;  // Sum 0 is always possible

    for (int coin : coins) {
        possible |= (possible << coin);
    }

    vector<int> result;
    for (int i = 1; i <= MAX_SUM; ++i) {
        if (possible[i]) result.push_back(i);
    }

    cout << result.size() << '\n';
    for (int sum : result) cout << sum << ' ';
    cout << '\n';

    return 0;
}
