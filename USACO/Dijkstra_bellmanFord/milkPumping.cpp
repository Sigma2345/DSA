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
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

void solve(){

    int n, m ; 
    cin>>n>>m ;

    vector< vector <vector<int> > > adj(n+1);    
    for(int i = 0 ; i<m ; i++){
        int a, b, c, f; 
        adj[a].pb({b, c, f});
        adj[b].pb({a, c, f});
    }
    vector<int> flow(n + 1, 0), cost(n+1, INT_MAX);
    flow[1] = INT_MAX;
    cost[1] = 0; 

    set< pair <int, int> > s; 
    s.insert({0, 1});
    while(!s.empty()){
        auto x = *s.begin();
        s.erase(s.begin());

        for(auto child: adj[x.second]){
            int netflow = min(flow[x.second], child[2]);
            int totalCost = cost[x.second] + child[1];  
        }
    }

}
int main()
{
freopen("pump.in", "r", stdin);
freopen("pump.out", "w", stdout);

    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}
