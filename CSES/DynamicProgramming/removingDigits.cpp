#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    // create subvector which will store the digits

    vector<int> dp(n + 1, INT_MAX);
    for (int i = 0; i < 10; i++)
    {
        dp[i] = 1;
    }
    dp[10] = 2;
    for (int i = 11; i <= n; i++)
    {
        vector<int> digits;

        int x = i;
        while (x)
        {
            if (x % 10)
                digits.push_back(x % 10);
            x /= 10;
        }
        for (int j = 0; j < digits.size(); j++)
        {
            dp[i] = min(dp[i], dp[i - digits[j]]);
        }
        dp[i]++;
    }
    cout << dp[n] << endl;

    return 0;
}
