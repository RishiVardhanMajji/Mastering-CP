#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> input(n);
        for (int i = 0; i < n; i++) {
            cin >> input[i];
        }

        int maxDelta = 0;
        int maxVal = input[0];
        for (int i = 1; i < n; i++) {
            if (input[i] < maxVal) {
                maxDelta = max(maxDelta, maxVal - input[i]);
            } else {
                maxVal = input[i]; 
            }
        }

        int T = 0;
        while ((1LL << T) - 1 < maxDelta) {
            T++;
        }

        cout << T << '\n';
    }
}
