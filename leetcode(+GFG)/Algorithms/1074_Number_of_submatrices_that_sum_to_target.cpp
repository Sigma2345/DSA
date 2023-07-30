// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pref[100][100];
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int r = matrix.size(), c = matrix[0].size();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                pref[i][j] = matrix[i][j];
                pref[i][j] += j > 0 ? pref[i][j - 1] : 0;
            }
        }
        int cnt = 0;
        for (int y1 = 0; y1 < c; y1++)
        {
            for (int y2 = y1; y2 < c; y2++)
            {
                vector<int> subarr(r);
                for (int i = 0; i < r; i++)
                {
                    if (y1 > 0)
                    {
                        subarr[i] = pref[i][y2] - pref[i][y1 - 1];
                    }
                    else
                        subarr[i] = pref[i][y2];

                    subarr[i] += i > 0 ? subarr[i - 1] : 0;
                }

                unordered_map<int, int> mp;
                mp[0] = 1;
                for (int i = 0; i < r; i++)
                {
                    int t = subarr[i] - target;
                    if (mp.count(t))
                    {
                        cnt += mp[t];
                    }
                    mp[subarr[i]]++;
                }
            }
        }

        return cnt;
    }
};

// the idea is to calculate the sum of rows 
// then y1 and y2 are two pointers on columns 
// for each pair (y1, y2) we calculate number of subarrays giving sum = target
