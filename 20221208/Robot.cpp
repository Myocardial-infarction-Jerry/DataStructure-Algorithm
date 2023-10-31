#include <bits/stdc++.h>
using namespace std;

#define INF 1E9

pair<int, int> direction[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b) { return pair<int, int>(a.first + b.first, a.second + b.second); }

int SPFA(const vector<vector<int>> &ter, int sx, int sy, int ex, int ey)
{
    int r = ter.size(), c = ter[0].size();
    vector<vector<int>> dis(r, vector<int>(c, INF));
    queue<pair<int, int>> que;
    vector<vector<bool>> sgn(r, vector<bool>(c, false));
    dis[sx][sy] = ter[sx][sy], que.push(pair<int, int>(sx, sy)), sgn[sx][sy] = true;

    for (; !que.empty();)
    {
        auto cur = que.front();
        for (int i = 0; i < 4; i++)
        {
            auto vec = cur + direction[i];
            if (vec.first >= 0 && vec.first < r && vec.second >= 0 && vec.second < c)
                if (dis[cur.first][cur.second] + ter[vec.first][vec.second] < dis[vec.first][vec.second])
                {
                    dis[vec.first][vec.second] = dis[cur.first][cur.second] + ter[vec.first][vec.second];
                    if (!sgn[vec.first][vec.second])
                        que.push(vec), sgn[vec.first][vec.second] = true;
                }
        }
        sgn[cur.first][cur.second] = false, que.pop();
    }

    return dis[ex][ey];
}

int main(int argc, char const *argv[])
{
    freopen("init.in", "r", stdin);
    int T;
    cin >> T;
    for (; T--;)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> ter(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> ter[i][j];

        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        cout << SPFA(ter, --sx, --sy, --ex, --ey) << endl;
    }
    return 0;
}
