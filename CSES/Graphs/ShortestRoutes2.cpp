#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INT64_MAX));

    for (int i = 0; i < m; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        dist[x][y] = dist[x][y] > d ? d: dist[x][y] ; 
        dist[y][x] = dist[x][y];
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    dist[i][j] = 0;
                else if (dist[i][k] != INT64_MAX && dist[k][j] != INT64_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        if (dist[x][y] == INT64_MAX)
            cout << -1 << endl; 
        else {
            cout<<dist[x][y]<<endl ; 
        }
    }

    return 0;
}
