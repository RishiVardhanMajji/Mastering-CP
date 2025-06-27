#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1);
    vector<int> pos(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    int rounds = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i] > pos[i + 1]) {
            rounds++;
        }
    }

    while (m--) {
        int a, b;
        cin >> a >> b;

        int x = arr[a], y = arr[b];
        set<pair<int, int>> affected;

        for (int d = -1; d <= 1; d++) {
            if (x + d >= 1 && x + d < n) affected.insert({x + d, x + d + 1});
            if (y + d >= 1 && y + d < n) affected.insert({y + d, y + d + 1});
        }

        for (auto [i, j] : affected) {
            if (pos[i] > pos[j]) rounds--;
        }

        swap(arr[a], arr[b]);
        swap(pos[x], pos[y]);

        for (auto [i, j] : affected) {
            if (pos[i] > pos[j]) rounds++;
        }

        cout << rounds << "\n";
    }

    return 0;
}
