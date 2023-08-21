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
ll MOD = 1e9 + 7;
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
#define int long long

void solve(){
    int n, m ; 
    cin>>n>>m ; 

    vvp64 h(n+1);
    forn(i,m){
        int x, y, z; 
        cin>>x>>y>>z ; 
        h[x].pb({y,z}); 
    }
    unordered_map<int, int> minFlights, maxFlights, dist, numRoutes ; 
    for(int i = 1; i<=n ; i++){
        minFlights[i] = 1e18 ; 
        maxFlights[i] = 0;
        dist[i] = 1e18; 
        numRoutes[i] = 0; 
    } 
    dist[1] = 0, minFlights[1] = 0, maxFlights[1] = 0, numRoutes[1] = 1;  
    set<pair<int, int>> s;
    s.insert({0,1});
    while(!s.empty()){
        auto x = *(s.begin()); 
        s.erase(s.begin());
        for(auto node: h[x.second]){
            if(dist[node.first] >= dist[x.second] + node.second ){
                if(s.find({dist[node.first], node.first }) != s.end()) s.erase(s.find({dist[node.first], node.first})); 
                if(dist[node.first] > dist[x.second] + node.second){
                    dist[node.first] = dist[x.second] + node.second ;
                    minFlights[node.first] = minFlights[x.second] + 1; 
                    maxFlights[node.first] = maxFlights[x.second] + 1; 
                    numRoutes[node.first] = numRoutes[x.second];   
                }
                else{
                    numRoutes[node.first] = (numRoutes[node.first] + numRoutes[x.second])%MOD ;
                    minFlights[node.first] = min(minFlights[node.first], minFlights[x.second] + 1);
                    maxFlights[node.first] = max(maxFlights[node.first], maxFlights[x.second] + 1);
                }
                s.insert({dist[node.first], node.first}); 
            }
        }
    }
    // for(int i = 1 ; i<=n;  i++){
        cout<<dist[n]<<' '<<numRoutes[n]<<' '<<minFlights[n]<<' '<<maxFlights[n]<<endl ;
    // }
}
signed main()
{
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

    fast_cin();
    ll t;
    t =1  ;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}