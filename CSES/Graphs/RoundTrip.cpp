#include<bits/stdc++.h>
using namespace std;

bool isCycle = false ; 
vector<bool> vis ; 

void printPath(vector<int> &p){
    // for(int x: p){
    //     std::cout << x <<' ' ;
    // }
    // std::cout << endl;
    int root = p[p.size()-1]; 
    int i = 0;
    for (; i < p.size() - 1; i++){
        if(p[i]==root)
            break; 
    }
    std::cout << (p.size() - i) << endl;
    for (int k = i; k < p.size(); k++)
       std::cout << p[k] << ' ';
    std::cout << endl;
}

void cycle(int prev, int src, vector<int> &parent, vector<vector<int>> &h){
    if(vis[src]){
        parent.push_back(src); 
        isCycle = true; 
        printPath(parent);
        parent.pop_back(); 
        return; 
    }

    vis[src] = true;
    parent.push_back(src);
    for (int i = 0; i < h[src].size() && !isCycle; i++){
        if(h[src][i]!=prev){
            cycle(src, h[src][i], parent, h);   
        }
    }
    parent.pop_back(); 
}

int main(){

    int n, m;
    cin >> n >> m ;
    vis.resize(n+1, false);

    vector<vector<int>> h(n + 1);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        h[a].push_back(b);
        h[b].push_back(a);
    }
    // std::cout << "HELLO" << endl; 
    // get cycles with length > 2
    vector<int> parent; 
    for (int i = 1; i <= n && !isCycle; i++){
        if(!vis[i]) cycle(i, i, parent, h); 
    }

    if(!isCycle){
        std::cout << "IMPOSSIBLE" << endl;
    }

    return 0; 
}
