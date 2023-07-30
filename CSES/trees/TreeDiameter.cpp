#include<bits/stdc++.h>
using namespace std; 
#define MAXN 200001

int dp[MAXN]; 
void DFS(vector<vector<int>> &v, int s, int e, int dist){
    for(int x: v[s]){
        if(x!=e){
            DFS(v, x, s, dist + 1); 
        }
    }
    dp[s] = dist;
}


int main(){

    memset(dp, -1, sizeof(dp)); 
    int n; 
    cin>>n ;
    vector<vector<int>> v(n + 1);

    for (int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x); 
    }
    DFS(v, 1, 0, 0); 
    int node = 0;
    for (int i = 1; i <= n; i++){
        if(dp[i] > dp[node]) node = i; 
    }

    // for (int i = 1; i <= n; i++){
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;

    // cout << "NODE IS " << node << endl;
    memset(dp, -1, sizeof(dp));
    DFS(v, node, 0, 0) ; 
    int ans = 0;
    for (int i = 1; i<=n ; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
