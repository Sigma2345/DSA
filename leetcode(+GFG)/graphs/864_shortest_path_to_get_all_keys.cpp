#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int r, c;
    vector<pair<int, int>> moves;
    long long f(int mask, int src_i, int src_j, vector<string> &grid)
    {
        if(mask==0) return 0; 
        queue<pair<int, int>> q;
        q.push({src_i, src_j});
        map<pair<int, int>, bool> vis;
        map<pair<int, int>, bool> isKeyUsed;
        int ans = INT_MAX, level = 0;
        while (!q.empty())
        {
            int s = q.size();
            for (int i = 0; i < s; i++){
                auto x = q.front();
                q.pop();
                
            }
            level++; 
        }
        return ans;
    }

    int shortestPathAllKeys(vector<string> &grid)
    {
        r = grid.size(), c = grid[0].length();
        moves.resize(4); 
        moves[0] = {0, 1}, moves[1] = {1, 0}, moves[2] = {0, -1}, moves[3] = {-1, 0};
        int keys = 0, src_i, src_j;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == '@')
                    src_i = i, src_j = j;
                else if ('a' <= grid[i][j] <= 'z')
                    keys++;
            }
        }
        long long ans = f(1 << keys, src_i, src_j, grid);
        return ans >= INT_MAX ? -1 : ans;
    }
};

int main(){
    return 0; 
}
