#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9 + 7;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define int long long

void solve() {

  int n, m;
  cin >> n >> m;

  vv32 h(n), back(n);
  v32 indeg(n, 0);
  v32 dp(n, 0);

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    h[x].pb(y);
    back[y].pb(x);
    indeg[y]++;
  }
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (!indeg[i]) {
      q.push(i);
    }
  }
    dp[0] = 1 ; 
  v32 topSort;

  while (!q.empty()) {
    int x = q.front();
    topSort.pb(x);
    q.pop();
    for (int y : h[x]) {
      indeg[y]--;
      if (indeg[y] == 0)
        q.push(y);
    }
  }

//   for (int i = 0; i < topSort.size(); i++)
//     cout << (topSort[i]+1) << ' ';

  for (int i = 0; i < topSort.size(); i++) {
    if(back[topSort[i]].size())
    {
      for (int y : back[topSort[i]]) {
        dp[topSort[i]] += dp[y];
        dp[topSort[i]] %= MOD; 
      }
    }
  }

//   for (int i = 0; i < topSort.size(); i++) {
//     cout << (topSort[i]+1) <<' '<<dp[topSort[i]]<<endl ;        
//   }

  cout<<dp[n-1]<<endl ; 

}
signed main() {
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);

  fast_cin();
  ll t;
  t = 1;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}