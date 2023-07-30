// http://www.usaco.org/index.php?page=viewproblem2&cpid=968
#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define vv32 vector<vector<int>>

int cnt = 1;
void DFS(vector<vector<int>> &v, int s, int e, vector<int> &d, string &a)
{
    d[s] = cnt;
    for (int t : v[s])
    {
        if (t != e && a[t - 1] == a[s - 1])
        {
            DFS(v, t, s, d, a);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vv32 v(n + 1);
    forn(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> d(n + 1, 0);
    string t = "";

    for (int i = 1; i <= n; i++)
    {
        if (!d[i])
        {
            DFS(v, i, -1, d, s);
            cnt++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        char x;
        cin >> a >> b >> x;
        if (d[a] == d[b])
        {
            t += s[a - 1] == x ? "1" : "0";
        }
        else
        {
            t += "1";
        }
    }
    cout << t << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    int t;
    t = 1;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
