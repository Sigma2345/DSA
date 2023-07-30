#include<bits/stdc++.h>
using namespace std; 
class Solution
{
public:
    map<int, int> oj;
    map<int, int> ej;
    int dp[20001][2];
    bool f(int s, int i, int turn)
    {
        // base
        if (i == s - 1)
            return true;
        if (turn == 0 && ej.find(i) == ej.end())
            return false;
        if (turn == 1 && oj.find(i) == oj.end())
            return false;
        // check
        if (dp[i][turn] != -1)
            return dp[i][turn];
        // rec
        return dp[i][turn] = turn == 0 ? f(s, ej[i], 1 - turn) : f(s, oj[i], 1 - turn);
    }
    int oddEvenJumps(vector<int> &arr)
    {
        memset(dp, -1, sizeof(dp));
        set<pair<int, int>> s;
        for (int i = 0; i < arr.size(); i++)
        {
            s.insert({arr[i], i});
        }
        for (int i = 0; i < arr.size(); i++)
        {
            s.erase({arr[i], i});
            auto x = s.lower_bound({arr[i], i});
            if (x != s.end())
            {
                oj[i] = x->second;
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            s.insert({-arr[i], i});
        }
        for (int i = 0; i < arr.size(); i++)
        {
            s.erase({-arr[i], i});
            auto x = s.lower_bound({-arr[i], i});
            if (x != s.end())
            {
                ej[i] = x->second;
            }
        }
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (f(arr.size(), i, 1))
                cnt++;
        }
        return cnt;
    }
};
int main(){
    return 0; 
}
