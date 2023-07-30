#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            if (s[j-1] == '#')
                mat[i][j] = 1;
        }
    }

    vector<vector<int>> up(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> down(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> left(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> right(n + 1, vector<int>(m + 1, 0));

    for (int i = 2; i<n ; i++){
        int dist = 0; 
        for (int j = 2; j < m; j++)
        {
            left[i][j] = dist ; 
            if(mat[i][j]==1)
                dist = 0;
            else
                dist++; 
        }

        dist = 0;
        for (int j = m - 1; j>=2; j--){
            right[i][j] = dist; 
            if(mat[i][j] ) dist = 0;
            else dist++;
        }
    }

    for (int j = 2; j < m; j++){
        int dist = 0 ;
        for (int i = 2; i < n ; i++){
            up[i][j] = dist; 
            if(mat[i][j])
                dist = 0; 
            else
                dist++;
        }

        dist = 0;
        for (int i = n - 1; i >= 2; i--){
            down[i][j] = dist; 
            if(mat[i][j])
                dist = 0; 
            else
                dist++;
        }
    }

    

    return 0;
}
