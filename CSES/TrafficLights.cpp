#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;

    set<int> lights = {0, x};
    map<int, int> segments;
    segments[x] = 1;

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;

        auto it = lights.upper_bound(p);
        int right = *it;
        int left = *prev(it);
        int len = right - left;
        segments[len]--;

        if (segments[len] == 0) segments.erase(len);

        segments[p - left]++;
        segments[right - p]++;

        lights.insert(p);

        cout << segments.rbegin()->first << " ";
    }
    cout << "\n";
}
