#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        string ans = s + "#" + s1;
        vector<int> v(ans.length(), 0);
        for (int i = 1; i < ans.length(); i++)
        {
            int j = v[i - 1];
            while (j > 0 && ans[i] != ans[j])
            {
                j = v[j - 1];
            }
            if (ans[i] == ans[j])
                j++;
            v[i] = j;
        }

        string subans = s.substr(v[v.size() - 1], s.length());
        reverse(subans.begin(), subans.end());
        return subans + s;
    }
};

int main()
{

    return 0;
}

/**
 * @brief idea is to use KMP algo
 * on string s + '# + reverse(s)
 * the last element would give last char where resemblence is found
 * then copy rest part and append it to the string
 */
