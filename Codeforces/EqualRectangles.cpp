#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canFormRectangles(vector<int>& sticks, int n) {
    sort(sticks.begin(), sticks.end());

    for (int i = 0; i < 4 * n; i += 2) {
        if (sticks[i] != sticks[i + 1])
            return false;
    }

    int area = sticks[0] * sticks[4 * n - 1];
    for (int i = 0; i < 2 * n; ++i) {
        int left = sticks[2 * i];
        int right = sticks[4 * n - 1 - 2 * i];
        if (left * right != area)
            return false;
    }

    return true;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> sticks(4 * n);
        for (int i = 0; i < 4 * n; ++i) {
            cin >> sticks[i];
        }

        if (canFormRectangles(sticks, n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
