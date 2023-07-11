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
#define int long long 

void solve()
{

    int n, q, time;
    cin >> n >> q >> time;
    vector< pair<int, int> > ans;
    pair<int, int> rud;
    for (int i = 0; i < n; i++){
        priority_queue<int, vector<int>, greater<int>> pq;
        forn(j, q){
            int x;
            cin >> x; 
            pq.push(x); 
        }
        int total_time = 0, penalty = 0;
        int cnt = 0;
        while(!pq.empty() && (pq.top()+total_time)<=time ){
            cnt++;
            total_time += pq.top();
            penalty += total_time;
            pq.pop(); 
        }
        ans.push_back({cnt, penalty}); 
        if(i==0) rud = {cnt, penalty}; 
    }
    sort(ans.begin(), ans.end(), [](const auto &a, const auto &b){
        if(a.first != b.first)
            return a.first > b.first;
        return a.second < b.second; 
    });

    // for(auto x: ans){
    //     cout << x.first << "," << x.second << ' '; 
    // }
    // cout<<endl; 

    for (int i = 0; i < n; i++){
        
        if(ans[i].second == rud.second && ans[i].first == rud.first){
            cout<<(i+1)<<endl;
            return; 
        }
    } 
}
signed main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
