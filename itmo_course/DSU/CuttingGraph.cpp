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

v32 par; 

int get(int x){
    return par[x] == -1 ? x : par[x] = get(par[x]); 
}

void merge(int x, int y){
    x = get(x), y = get(y);
    if(x==y)
        return ; 
    if(x>y)
        swap(x, y);
    par[y] = x; 
}

void solve(){

    int n, m, k;
    cin >> n >> m >> k;

    par.resize(n + 1, -1);

    vp32 arr(m); 
    forn(i, m){
        cin >> arr[i].first >> arr[i].second; 
    }

    set< pair<int, int> > cutEdges; 

    // 1 -> cut , 2 -> ask
    vv32 queries(k);
    forn(i,k){
        int x, y; 
        string s;
        cin>>s>>x>>y ; 
        if(s=="cut"){
            cutEdges.insert({min(x, y), max(x, y)});
            queries[i] = {1, x, y}; 
        }
        else{
            queries[i] = {2, x, y}; 
        }
    }

    forn(i, m){
        if (cutEdges.find({min(arr[i].first, arr[i].second), max(arr[i].first, arr[i].second)}) == cutEdges.end()){
            merge(arr[i].second, arr[i].first); 
        }
    }

    vector<bool> ans;
    for (int i = k - 1; i >= 0; i--){
        if(queries[i][0] == 1){
            merge(queries[i][1], queries[i][2]); 
        }
        else
            ans.push_back(get(queries[i][1]) == get(queries[i][2])); 
    }

    reverse(begin(ans), end(ans));
    for (int i = 0; i < sz(ans); i++){
        if(ans[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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
