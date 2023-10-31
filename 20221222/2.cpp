#include <bits/stdc++.h>
using namespace std;

int main()
{
    string st1, st2, st;
    map<string, string> dic;

    getline(cin, st);
    while (st != "")
    {
        st1 = "";
        st2 = "";
        int flag = -1;
        for (int i = 0; i < st.size(); i++)
        {
            if (st[i] == ' ')
            {
                flag = i + 1;
                break;
            }
            st1 += st[i];
        }
        for (int i = flag; i < st.size(); i++)
            st2 += st[i];
        dic[st2] = st1;
        getline(cin, st);
    }

    while (cin >> st)
        if (dic.count(st) == 0)
            cout << "eh\n";
        else
            cout << dic[st] << endl;

    return 0;
}
