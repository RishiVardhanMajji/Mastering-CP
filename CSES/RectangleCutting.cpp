#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    if (a < b) {
        swap(a, b);
    }
    int moves = 0;
    while (b > 0) {
        moves += a / b;
        int rem = a % b;
        a = b;
        b = rem;
    }
    cout << moves - 1 << endl;
    return 0;
}