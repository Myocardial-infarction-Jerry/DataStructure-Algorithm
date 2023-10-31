#include <bits/stdc++.h>
using namespace std;

#define INF 1E9

struct Edge
{
    int vec, cost;
    Edge *next;
    Edge(int _vec = 0, int _cost = INF, Edge *_next = nullptr) : vec(_vec), cost(_cost), next(_next) {}
    ~Edge()
    {
        if (next != nullptr)
            delete next;
    }
};

void SPFA(int start, const vector<Edge *> &finalEdge, vector<int> &dis)
{
    int n = dis.size() - 1;
    queue<int> que;
    vector<bool> sgn(n + 1, false);
    que.push(start), sgn[start] = true, dis[start] = 0;
    for (; !que.empty();)
    {
        int cur = que.front();
        for (Edge *edge = finalEdge[cur]; edge != nullptr; edge = edge->next)
            if (dis[cur] + edge->cost < dis[edge->vec])
            {
                dis[edge->vec] = dis[cur] + edge->cost;
                if (!sgn[edge->vec])
                    que.push(edge->vec), sgn[edge->vec] = true;
            }
        que.pop(), sgn[cur] = false;
    }

    for (int i = 1; i <= n; i++)
        if (dis[i] == INF)
            dis[i] = -1;
}

int main(int argc, char const *argv[])
{
    freopen("init.in", "r", stdin);
    int n, m, q;
    cin >> n >> m >> q;
    vector<Edge *> finalEdge(n + 1, nullptr);
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, INF));
    for (; m--;)
    {
        int u, v, w;
        cin >> u >> v >> w;
        finalEdge[u] = new Edge(v, w, finalEdge[u]);
    }

    for (int i = 1; i <= n; i++)
        SPFA(i, finalEdge, dis[i]);

    for (; q--;)
    {
        int u, v;
        cin >> u >> v;
        cout << dis[u][v] << endl;
    }

    for (auto &edge : finalEdge)
        delete edge;

    return 0;
}
