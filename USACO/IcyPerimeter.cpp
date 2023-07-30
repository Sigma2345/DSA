// http://www.usaco.org/index.php?page=viewproblem2&cpid=895
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

    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int n;
    cin >> n;

    vv32 mat(n, v32(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char x;
            cin >> x;
            if (x == '#')
            {
                mat[i][j] = 1;
            }
        }
    }

    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++){
    //         cout << mat[i][j] << ' ';
    //     }
    //     cout<<endl; 
    // }

        int maxAr = 0, peri = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                // cout << i << ' ' << j << ' ' << endl ;
                int s1 = 0, s2 = 0, s3 = 0;
                int ar = 0;
                queue<pair<int, int>> q;
                q.push({i, j}); 
                while (q.size())
                {
                    auto cor = q.front();
                    q.pop();
                    int x = cor.first, y = cor.second;
                    mat[x][y] = -1; 
                    int cnt = 4;
                    for (int i = 0; i < 4; i++){
                        int nx = x + dir[i][0], ny = y + dir[i][1] ;
                        if(nx>=0 && ny>=0 && nx<n && ny<n && mat[nx][ny]!=0){
                            cnt--; 
                            if(mat[nx][ny]==1){
                                q.push({nx, ny});
                                mat[nx][ny] = -1; 
                                ar++; 
                            }
                        } 
                    }
                    if(cnt==1)
                        s1++;
                    else if(cnt==2)
                        s2++; 
                    else if(cnt==3)
                        s3++; 
                }
                ar++;
                // std::cout << ar << endl;
                if(ar > maxAr){
                    maxAr = ar;
                    peri = 3 * s3 + 2 * s2 + s1; 
                }
                else if(ar==maxAr){
                    peri = min(peri, 3 * s3 + 2 * s2 + s1); 
                }
            }
        }
    }
    cout<<maxAr<<' '<<peri<<endl ; 
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
