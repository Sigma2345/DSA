// http://www.usaco.org/index.php?page=viewproblem2&cpid=992
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
ll MOD = 998244353;
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

v32 p;
int cnt = 0;
int find(int x) { return p[x] == -1 ? x : p[x] = find(p[x]); }

void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y)
    return;
  if (x > y)
    swap(x, y);
  p[y] = x;
}

void resolve(v32 &pos, int indx) {
  int num = pos[indx];
  if (pos[indx] == indx)
    return;
  if (find(num) == find(indx)) {
    int val = pos[num];
    pos[num] = num;
    cnt++ ;
    pos[indx] = val;
    if(val==indx) cnt++ ; 
  }
}

void solve() {

  int n, w;
  cin >> n >> w;
  p.resize(n, -1);
  v32 pos(n);
  for (int i = 0; i < n; i++) {
    cin >> pos[i];
    pos[i]--;
  }
  vv32 wormholes(w);
  for (int i = 0; i < w; i++) {
    int x, y, z;
    cin>>x>>y>>z ;
    wormholes[i] = {z, x - 1, y - 1};
  }
  sort(rbegin(wormholes), rend(wormholes));

  for (int i = 0; i < n; i++) {
    if (pos[i] == i)
      cnt++;
  }
  if (cnt == n) {
    cout << -1 << endl;
    return;
  }

  int indx = 0;
  for (; indx < w && cnt < n; indx++) {
    merge(wormholes[indx][1], wormholes[indx][2]);
    resolve(pos, wormholes[indx][1]);
    resolve(pos, wormholes[indx][2]);
  }
  indx--;
  cout<<wormholes[indx][0]<<endl ;
}
int main() {
  freopen("wormhole.in", "r", stdin);
  freopen("wormhole.out", "w", stdout);

  fast_cin();
  ll t;
  t = 1;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}