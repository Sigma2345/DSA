#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{

    int h, w, n;
    cin >> h >> w >> n;


    vector<vector<int>> mat(h + 1, vector<int>(w + 1, 0));
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
    }

    vector<vector<int>> dp(h + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            dp[i][j] += mat[i][j] ? 1 : 0;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (mat[i][j] == 0)
            {
                int s = 1, e = min(i, j);
                int ans = -1; 
                while (s <= e)
                {
                    int mid = (s + e) / 2;
                    bool check = (dp[i][j] - dp[i-mid][j] - dp[i][j-mid] + dp[i-mid][j-mid]) == 0; 
                    if(check){
                        ans = mid;
                        s = mid + 1;
                    }
                    else{
                        e = mid - 1; 
                    }
                }
                cnt += ans;     
            }
        }
    }

    cout << cnt << endl; 
    return 0;
}
