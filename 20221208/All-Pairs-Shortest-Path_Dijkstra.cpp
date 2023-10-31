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

void dijkstra(int start, const vector<Edge *> &finalEdge, vector<int> &dis)
{
    int n = dis.size() - 1;
    priority_queue<pair<int, int>> hep;
    vector<bool> sgn(n + 1, false);
    hep.push(pair<int, int>(0, start));
    for (; !hep.empty();)
    {
        int cur;
        for (; sgn[hep.top().second]; hep.pop())
            ;
        dis[cur = hep.top().second] = hep.top().first;
        sgn[cur] = true;
        hep.pop();
        for (Edge *edge = finalEdge[cur]; edge != nullptr; edge = edge->next)
            if (!sgn[edge->vec])
                hep.push(pair<int, int>(dis[cur] + edge->cost, edge->vec));
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
        dijkstra(i, finalEdge, dis[i]);

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
