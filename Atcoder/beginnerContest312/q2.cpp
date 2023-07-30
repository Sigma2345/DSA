#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> dp(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        dp[i] = s;
    }

    for (int i = 0; i + 8 < n; i++)
    {
        for (int j = 0; j + 8 < m; j++)
        {
            bool x1 = true, x2 = true;
            for (int x = 0; x < 3 && x1; x++)
            {
                for (int y = 0; y < 3 && x1; y++)
                {
                    if (dp[i+x][j+y] != '#' || dp[i + 8 - x][j + 8 - y] != '#')
                        x1 = false;
                }
            }
            if (!x1)
                continue;

            for (int row = 0; row < 4 && x2; row++)
            {
                if (dp[i + row][j + 3] != '.' || dp[i + 8 - row][j + 5] != '.')
                    x2 = false;
            }

            for (int col = 0; col < 3 && x2; col++)
            {
                if (dp[i + 3][j + col] != '.' || dp[i + 5][j + 8 - col] != '.')
                    x2 = false;
            }

            if (x1 && x2)
            {
                cout << (i + 1) << ' ' << (j + 1) << endl;
            }
        }
    }

    return 0;
}
