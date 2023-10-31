#include <bits/stdc++.h>
using namespace std;

#define INF 1E9

pair<int, int> direction[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b) { return pair<int, int>(a.first + b.first, a.second + b.second); }

int BFS(const vector<vector<int>> &map, int sx, int sy, int tx, int ty)
{
    int n = map.size(), m = map[0].size();
    queue<pair<int, int>> que;
    vector<vector<int>> dis(n, vector<int>(m, INF));
    vector<vector<int>> sgn(n, vector<int>(m, false));
    que.push(pair<int, int>(sx, sy));
    dis[sx][sy] = 0;
    sgn[sx][sy] = true;

    for (; !que.empty();)
    {
        auto cur = que.front();
        for (int i = 0; i < 4; i++)
        {
            auto vec = cur + direction[i];
            if (vec.first >= 0 && vec.first < n && vec.second >= 0 && vec.second < m && !map[vec.first][vec.second])
                if (dis[cur.first][cur.second] + 1 < dis[vec.first][vec.second])
                {
                    dis[vec.first][vec.second] = dis[cur.first][cur.second] + 1;
                    if (!sgn[vec.first][vec.second])
                        que.push(vec), sgn[vec.first][vec.second] = true;
                }
        }
        sgn[cur.first][cur.second] = false, que.pop();
    }

    return dis[tx][ty];
}

int main(int argc, char const *argv[])
{
    freopen("init.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    sx--, sy--, tx--, ty--;
    int ans = BFS(map, sx, sy, tx, ty);
    if (ans == INF)
        cout << "No" << endl;
    else
        cout << ans << endl;
    return 0;
}
