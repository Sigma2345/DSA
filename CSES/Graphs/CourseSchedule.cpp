#include <bits/stdc++.h>  
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())


void solve() {

  int n, m;
  cin>>n>>m ;

  vector<vector<int>> h(n);
  vector<int> indeg(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    h[x].pb(y);
    indeg[y]++;
  }

  queue<int> q;
  for (int i = 0; i < n; i++)
    if (!indeg[i])
      q.push(i);

  vector<int> ans ; 
  
  while (!q.empty()) {
    int x = q.front();
    ans.push_back(x); 
    q.pop();
    for (int y : h[x]) {
      indeg[y]--;
      if(indeg[y]==0) q.push(y); 
    }
  }

  if (ans.size() < n) {
    cout<<"IMPOSSIBLE"<<endl ;
    return ;
  }

  for (int x : ans) {
    cout<<(x+1)<<' ' ;
  }
  
}
int main()
{
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

    fast_cin();
    ll t;
    t = 1; 
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}