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
// #define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define int long long 

map<pair<int, pair<int, int>>, int> mp; 

int f(string &s, int i, int cnt1, int cnt2){
    if (i == s.length())
        return cnt1 == cnt2; 
    if(s.length()-i < (cnt1-cnt2)) return 0;
    if (cnt1 < cnt2)
        return 0; 
    

    if(mp.find({i, {cnt1, cnt2}}) != mp.end())
        return mp[{i, {cnt1, cnt2}}]; 

    if(s[i]=='?'){
        if(cnt1 > cnt2)
            return mp[{i, {cnt1, cnt2}}] = (f(s, i + 1, cnt1 + 1, cnt2) % MOD + f(s, i + 1, cnt1, cnt2 + 1) % MOD) % MOD;
        else {
            return mp[{i, {cnt1, cnt2}}]  = f(s, i + 1, cnt1 + 1, cnt2) % MOD;
        }
    }

    if(s[i]=='(')
        return mp[{i, {cnt1, cnt2}}]  = f(s, i + 1, cnt1 + 1, cnt2) % MOD;
    return mp[{i, {cnt1, cnt2}}]  = f(s, i + 1, cnt1, cnt2 + 1) % MOD;
}

void solve(){

    string s;
    cin >> s;

    cout << f(s, 0, 0, 0) << endl;
}
signed main()
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
