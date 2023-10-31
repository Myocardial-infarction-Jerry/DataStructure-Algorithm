#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int vec;
    Edge* next;
    Edge(int _vec = 0, Edge* _next = NULL) : vec(_vec), next(_next) {}
    ~Edge()
    {
        if (next != NULL)
            delete next;
    }
};

bool judge(int cur, vector<bool>& sgn, vector<Edge*>& finalEdge)
{
    if (sgn[cur])
        return false;
    sgn[cur] = true;

    for (Edge* edge = finalEdge[cur]; edge != NULL; edge = edge->next)
        if (!judge(edge->vec, sgn, finalEdge))
            return false;

    sgn[cur] = false;
    return true;
}

int main(int argc, char const* argv[])
{
    freopen("init.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<Edge*> finalEdge(n + 1, NULL);
    for (; m--;)
    {
        int u, v;
        cin >> u >> v;
        finalEdge[u] = new Edge(v, finalEdge[u]);
    }

    int ans = 1;
    vector<bool> sgn(n + 1, false);
    for (int i = 1; i <= n; i++)
        if (!judge(i, sgn, finalEdge))
        {
            ans = 0;
            break;
        }

    cout << ans << endl;

    for (int i = 0; i <= n; i++)
        delete finalEdge[i];
    return 0;
}
