// usaco.org/index.php?page=viewproblem2&cpid=789
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

v32 p;
v32 sz ;

int find(int x) { return p[x] == -1 ? x : p[x] = find(p[x]); }
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y)
    return;
  if (x > y)
    swap(x, y);
  p[y] = x;
  sz[x] += sz[y] ; 
}

void solve() {
  int n, q;
  cin >> n >> q;

  p.resize(n+1,-1), sz.resize(n+1, 1); 
  vv32 edges;
  for (int i = 0; i < n - 1; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    edges.push_back({z, x, y});
  }
  vv32 queries(q);
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    queries[i] = {x, y, i}; 
  }
  sort(rbegin(queries), rend(queries));
  sort(rbegin(edges), rend(edges));

  v32 ans(q);
  int idx = 0;
  for (int i = 0; i < queries.size(); i++) {
    while (idx < edges.size() && edges[idx][0] >= queries[i][0]) {
      merge(edges[idx][1], edges[idx][2]); 
      idx++; 
    }
    ans[queries[i][2]] = sz[find(queries[i][1])] - 1; 
  }
  for(int i = 0; i<q ; i++) cout<<ans[i]<<endl ; 
}
int main()
{
freopen("mootube.in", "r", stdin);
freopen("mootube.out", "w", stdout);

    fast_cin();
    ll t;
    t = 1;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}