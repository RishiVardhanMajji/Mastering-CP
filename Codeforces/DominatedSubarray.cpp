#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_map<int, int> last;
        int answer = n + 1;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (last.count(a[i])) {
                int len = i - last[a[i]] + 1;
                if (len < answer) answer = len;
            }
            last[a[i]] = i;
        }

        if (answer == n + 1)
            cout << -1 << "\n";
        else
            cout << answer << "\n";
    }
    return 0;
}
