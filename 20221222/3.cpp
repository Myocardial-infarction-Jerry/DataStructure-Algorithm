#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) { return a > b; }

int main()
{
    int n, q;
    while (cin >> n >> q)
    {
        int size[1010];
        int flag[1010];
        for (int i = 0; i < n; i++)
        {
            cin >> size[i];
            flag[i] = 0;
        }
        sort(size, size + n, cmp);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (flag[i] != 0)
                continue;
            int volume = size[i];
            flag[i] = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (flag[j] != 0)
                    continue;
                if (volume + size[j] <= q)
                {
                    volume = volume + size[j];
                    flag[j] = 1;
                }
            }
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
