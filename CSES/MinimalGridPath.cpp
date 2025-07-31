#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];

    using State = tuple<string, int, int>;  
    priority_queue<State, vector<State>, greater<State>> pq;

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    pq.push({string(1, grid[0][0]), 0, 0});
    visited[0][0] = true;

    while (!pq.empty()) {
        auto [path, r, c] = pq.top();
        pq.pop();

        if (r == n - 1 && c == n - 1) {
            cout << path << '\n';
            return 0;
        }

        if (r + 1 < n && !visited[r + 1][c]) {
            pq.push({path + grid[r + 1][c], r + 1, c});
            visited[r + 1][c] = true;
        }
        if (c + 1 < n && !visited[r][c + 1]) {
            pq.push({path + grid[r][c + 1], r, c + 1});
            visited[r][c + 1] = true;
        }
    }

    return 0;
}
