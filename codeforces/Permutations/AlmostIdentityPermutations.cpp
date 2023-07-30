#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;

    // Use Pascal's Identity to precalculate combinations.
    ll c[n + 1][k + 1];
    fill_n(&c[0][0], (n + 1) * (k + 1), 0);
    for (int i = 0; i <= n; i++)
    {
        c[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }

    ll ans = 0;
    // Iterate over number of positions to shuffle.
    for (int i = 0; i <= k; i++)
    {

        // Calculate number of valid permutations result in all positions
        // shuffled.
        int a[i];
        for (int j = 0; j < i; j++)
            a[j] = j;
        int amt = 0;
        do
        {
            bool valid = 1;
            for (int j = 0; j < i; j++)
                if (a[j] == j)
                    valid = 0;
            if (valid)
                amt++;
        } while (next_permutation(a, a + i));

        // Add the number of valid permutations of i elements multiplied by the
        // number of ways to choose i elements.
        ans += c[n][i] * amt;
    }

    cout << ans << endl;
}
