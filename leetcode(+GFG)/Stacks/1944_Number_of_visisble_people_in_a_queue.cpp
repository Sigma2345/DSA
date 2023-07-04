// https:// leetcode.com/problems/number-of-visible-people-in-a-queue/
#include<bits/stdc++.h>
using namespace std; 
class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> arr(n, 0);
        if (n == 1)
            return arr;
        if (n == 2)
        {
            arr[0] = 1;
            return arr;
        }
        stack<int> s;
        for (int i = n - 1; i >= 0; i--)
        {
            int numPop = 0;
            while (!s.empty() && s.top() < heights[i])
            {
                s.pop();
                numPop++;
            }
            if (!s.empty())
                numPop++;
            s.push(heights[i]);
            arr[i] = numPop;
        }
        return arr;
    }
};
// monotonic stack
