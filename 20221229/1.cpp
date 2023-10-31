#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    freopen("init.in", "r", stdin);
    int T;
    cin >> T;
    for (; T--;)
    {
        int n;
        cin >> n;
        queue<int> que;
        for (int i = 1; i <= n; i++)
            que.push(i);
        for (int i = 1; i <= n; i++)
        {
            cout << que.front() << " ";
            que.pop();
            que.push(que.front());
            que.pop();
        }
        cout << endl;
    }
    return 0;
}
