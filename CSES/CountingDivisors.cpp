#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e6 + 1;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int &x : nums)
        cin >> x;

    vector<int> divisor_count(MAX, 0);

    for (int i = 1; i < MAX; i++) {
        for (int j = i; j < MAX; j += i) {
            divisor_count[j]++;
        }
    }

    for (int x : nums) {
        cout << divisor_count[x] << "\n";
    }

    return 0;
}
