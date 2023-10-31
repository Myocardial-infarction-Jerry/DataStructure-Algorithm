#include <bits/stdc++.h>
using namespace std;

struct Road
{
    int vec;
    Road* nxt;
    Road(int _vec, Road* _nxt) : vec(_vec), nxt(_nxt) {}
    ~Road()
    {
        if (nxt != NULL)
            delete nxt;
    }
};

void DFS(int cur, const vector<Road*>& final_road,
    vector<pair<int, int> >& IOtime, int& time)
{
    if (IOtime[cur].first)
        return;

    IOtime[cur].first = ++time;

    for (Road* road = final_road[cur]; road != NULL; road = road->nxt)
        DFS(road->vec, final_road, IOtime, time);

    IOtime[cur].second = ++time;
}

int main()
{
    freopen("init.in", "r", stdin);

    int T;
    cin >> T;
    for (; T--;)
    {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int> > edge;
        for (; m--;)
        {
            int u, v;
            cin >> u >> v;
            edge.push_back(pair<int, int>(u, v));
            edge.push_back(pair<int, int>(v, u));
        }
        sort(edge.rbegin(), edge.rend());

        vector<Road*> final_road(n + 1, NULL);
        vector<pair<int, int> > IOtime(n + 1, pair<int, int>(0, 0));

        for (auto& cur:edge)
            final_road[cur.first] = new Road(cur.second, final_road[cur.first]);


        int time = 0;
        for (int i = 1; i <= n; i++)
            DFS(i, final_road, IOtime, time);

        for (int i = 1; i <= n; i++)
            cout << i << ":" << IOtime[i].first << "-" << IOtime[i].second << endl;
        cout << "---" << endl;

        for (int i = 1; i <= n; i++)
            delete final_road[i];
    }
    return 0;
}