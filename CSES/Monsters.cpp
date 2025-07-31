#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<int>> dist_monster, dist_player;
vector<vector<pair<int, int>>> parent;
pair<int, int> start;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};
char rev_dir[] = {'D', 'U', 'R', 'L'};

bool is_boundary(int x, int y) {
    return x == 0 || y == 0 || x == n-1 || y == m-1;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    dist_monster.assign(n, vector<int>(m, 1e9));
    dist_player.assign(n, vector<int>(m, -1));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));

    queue<pair<int, int>> q;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'M') {
                q.push({i, j});
                dist_monster[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (grid[nx][ny] != '#' && dist_monster[nx][ny] > dist_monster[x][y] + 1) {
                    dist_monster[nx][ny] = dist_monster[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    q.push(start);
    dist_player[start.first][start.second] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (is_boundary(x, y)) {
            string path;
            while (make_pair(x, y) != start) {
                auto [px, py] = parent[x][y];
                for (int d = 0; d < 4; ++d) {
                    if (x - dx[d] == px && y - dy[d] == py) {
                        path += dir[d];
                        break;
                    }
                }
                x = px;
                y = py;
            }
            reverse(path.begin(), path.end());
            cout << "YES\n" << path.size() << "\n" << path << "\n";
            return 0;
        }

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (grid[nx][ny] != '#' && dist_player[nx][ny] == -1 && dist_player[x][y] + 1 < dist_monster[nx][ny]) {
                    dist_player[nx][ny] = dist_player[x][y] + 1;
                    parent[nx][ny] = {x, y};
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << "NO\n";
    return 0;
}
