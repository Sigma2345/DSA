#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<int> T(n);
    for (auto &t : T)
        cin >> t;

    // store the tops of each tower in the set
    // every time item added in that tower replace element in set with new top val

    multiset<int> s;
    int ans = 1;
    s.insert(T[0]);
    for (int i = 1; i < T.size(); i++)
    {
        auto x = s.upper_bound(T[i]);
        if (x == s.end()) /// new tower needed
            ans += 1;

        // upper bound always gives greater element
        else
        {
            s.erase(x);
        }
        s.insert(T[i]);
    }

    cout << ans << endl;

    return 0;
}
