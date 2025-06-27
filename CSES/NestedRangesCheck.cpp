#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Range {
    int start, end, index;
};

int main() {
    int n;
    cin >> n;

    vector<Range> ranges(n);
    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].start >> ranges[i].end;
        ranges[i].index = i;
    }
    sort(ranges.begin(), ranges.end(), [](Range &a, Range &b) {
        if (a.start == b.start)
            return a.end > b.end;
        return a.start < b.start;
    });

    vector<int> contains(n, 0), contained_by(n, 0);

    int max_end = 0;
    for (auto &r : ranges) {
        if (r.end <= max_end)
            contained_by[r.index] = 1;
        max_end = max(max_end, r.end);
    }

    int min_end = 1e9 + 1;
    for (int i = n - 1; i >= 0; --i) {
        if (ranges[i].end >= min_end)
            contains[ranges[i].index] = 1;
        min_end = min(min_end, ranges[i].end);
    }

    for (int val : contains) cout << val << " ";
    cout << "\n";
    for (int val : contained_by) cout << val << " ";
    cout << "\n";

    return 0;
}
