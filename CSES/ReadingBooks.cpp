#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> books(n);
    long long sum = 0, max_time = 0;

    for (int i = 0; i < n; ++i) {
        cin >> books[i];
        sum += books[i];
        max_time = max(max_time, books[i]);
    }

    cout << max(sum, 2 * max_time) << "\n";
    return 0;
}
