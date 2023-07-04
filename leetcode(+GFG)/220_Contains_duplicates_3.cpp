// https://leetcode.com/problems/contains-duplicate-iii/description/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
    {
        multiset<int> s;
        int n = nums.size();
        for (int i = 0; i <= indexDiff && i < n; i++)
        {
            s.insert(nums[i]);
        }

        for (int i = 0; i < n - 1; i++)
        {
            s.erase(s.find(nums[i]));
            auto x = s.lower_bound(nums[i] - valueDiff);
            if (x != s.end() && *x <= (nums[i] + valueDiff))
            {
                return true;
            }

            if (i + indexDiff + 1 < n)
            {
                s.insert(nums[i + indexDiff + 1]);
            }
        }
        return false;
    }
};
// window of length indexDiff
// find lower bound of nums[i] - valDiff 
// and check whether any element in range
// if found return true
