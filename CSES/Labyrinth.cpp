#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> visited;
vector<vector<char>> moveFrom;
vector<vector<pair<int, int>>> parent;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m &&
           grid[x][y] != '#' && !visited[x][y];
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));
    moveFrom.assign(n, vector<char>(m));
    parent.assign(n, vector<pair<int, int>>(m));

    pair<int, int> start, end;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    bool found = false;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (make_pair(x, y) == end) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (is_valid(nx, ny)) {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                moveFrom[nx][ny] = dir[i];
                q.push({nx, ny});
            }
        }
    }

    if (!found) {
        cout << "NO\n";
        return 0;
    }

    string path;
    pair<int, int> cur = end;
    while (cur != start) {
        char step = moveFrom[cur.first][cur.second];
        path += step;
        cur = parent[cur.first][cur.second];
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.length() << "\n";
    cout << path << "\n";

    return 0;
}
