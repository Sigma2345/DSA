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

void solve()
{

    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<int> dp(n);
    dp[0] = 1;
    map<int, int> mp; 
    for (int i = 0; i < n; i++)
    {
        if(mp.find(a[i]-1) == mp.end()){
            dp[i] = 1; 
            if(mp.find(a[i])==mp.end())
                mp[a[i]] = i; 
            else{
                mp[a[i]] = dp[i] > dp[mp[a[i]]] ? i : mp[a[i]]; 
            }
        } 
        else{
            dp[i] = dp[mp[a[i] - 1]] + 1; 
            if(mp.find(a[i]) == mp.end())
                mp[a[i]] = i; 
            else{
                mp[a[i]] = dp[i] > dp[mp[a[i]]] ? i : mp[a[i]]; 
            }
        }
    }

    // for (int x: dp){
    //     cout << x << ' '; 
    // }
    // cout << endl;

    int ans = *max_element(dp.begin(), dp.end());
    vector<int> seq;
    int cnt = ans;
    for (int j = n - 1; j >= 0; j--)
    {
        if (cnt == dp[j])
        {
            if (seq.size() == 0)
            {
                seq.push_back(j);
                cnt--;
            }
            else
            {
                int indx = seq[seq.size() - 1];
                if (a[j] == a[indx] - 1)
                {
                    seq.push_back(j);
                    cnt-- ; 
                }
            }
        }
    }
    cout << ans << endl;
    for (int i = seq.size() - 1; i >= 0; i--)
    {
        cout << (seq[i] + 1) << ' ';
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
