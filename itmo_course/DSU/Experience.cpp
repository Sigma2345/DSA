#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> p, sz, extra, points;

    DSU(int n)
    {
        p.resize(n, -1);
        sz.resize(n, 1);
        extra.resize(n, 0);
        points.resize(n, 0);
    }

    int get(int x)
    {
        return p[x] == -1 ? points[x] : points[x] - extra[x] + get(p[x]);
    }

    int find(int u)
    {
        return p[u] == -1 ? u : find(p[u]);
    }

    void merge(int u, int v)
    {
        u = find(u), v = find(v);
        if (u == v)
            return;
        if (sz[u] < sz[v])
        {
            swap(u, v);
        }
        p[v] = u;
        sz[u] += sz[v];
        int x = points[u];
        extra[v] = x;
    }
};

int main()
{

    int n, q;
    cin >> n >> q;

    n++; 

    DSU d(n); 

    for (int i = 0; i < q; i++){
        string s; 
        cin>>s ; 
        if(s=="join"){
            int x, y;
            cin >> x >> y; 
            d.merge(x, y); 
        }
        else if(s=="add"){
            int x, val;
            cin >> x >> val;
            int par = d.find(x);
            d.points[par] += val; 
        }
        else{
            int x; 
            cin>>x ;
            cout << d.get(x) << endl; 
        }
    }

        return 0;
}
