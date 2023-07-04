#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <iomanip>
#include <fstream>

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
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

bool vis[200001];
int dis[200001];

void solve()
{
    memset(dis, -1, sizeof(dis));
    memset(vis, false, sizeof(vis));
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            queue<int> q;
            map<int, int> mp; 
            int x = i, cnt = 0 ; 
            while(!vis[x] &&  dis[x]==-1){
                mp[x] = cnt++;
                vis[x] = true;
                q.push(x); 
                x = a[x]; 
            }  
            if(dis[x]!=-1){
                while(!q.empty()){
                    dis[q.front()] = q.size() + dis[x];
                    q.pop(); 
                }
            }
            else{
                while(!q.empty() && q.front()!=x){
                    dis[q.front()] = cnt - mp[q.front()];
                    q.pop();
                }
                int s = q.size();
                while(!q.empty()){
                    dis[q.front()] = s;
                    q.pop(); 
                }
            }
        }
    }

    for (int i = 1; i <= n; i++){
        cout << dis[i] << ' ';
    }
    cout << endl;
}
int main()
{
    fast_cin();
    ll t;
    t = 1;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
