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

int numComponents = 1 ;
v32 p ; 
v32 vis ;

int get(int x) { return p[x] == -1 ? x : p[x] = get(p[x]); }

void merge(int x, int y) {
  x = get(x), y = get(y);
  if (x == y)
    return;

  if (x > y)
    swap(x, y);
  p[y] = x;
  numComponents-- ; 
}

void solve(){
    int n, m ;
    cin >> n >> m;
    p.resize(n+1, -1), vis.resize(n+1, 0) ;
    vv32 h(n+1) ; 
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      h[x].pb(y), h[y].pb(x);
    }

    v32 arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    vis[arr[n-1]] = 1;

    vector<string> ans;
    ans.push_back("YES");

    for (int i = n - 2; i >= 0; i--) {
      vis[arr[i]] = 1;
      numComponents++ ; 
      for (int x: h[arr[i]]) {
        if (vis[x]) {
          merge(x, arr[i]) ;
        }
      }
      if (numComponents != 1) {
        ans.push_back("NO") ;
      } else {
        ans.push_back("YES"); 
      }
    }

    reverse(ans.begin(), ans.end());
    // cout<<ans.size()<<endl ;
    for (int i = 0; i < ans.size(); i++) {
      cout<<ans[i]<<endl ;
    }
}
int main()
{
freopen("closing.in", "r", stdin);
freopen("closing.out", "w", stdout);

    fast_cin();
    ll t;
    t = 1;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}