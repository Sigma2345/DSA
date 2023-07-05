#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::vector;

int main()
{
    int limit;
    int type_num;
    std::cin >> limit >> type_num;

    std::map<int, vector<pair<int, int>>> by_weight;
    for (int t = 0; t < type_num; t++)
    {
        int value;
        int weight;
        int amt;
        std::cin >> value >> weight >> amt;
        if (weight <= limit && amt > 0)
        {
            by_weight[weight].push_back({value, amt});
        }
    }

    /*
     * best[i][j] contains the most value we can
     * get using j weight and the first i weight types
     */
    vector<vector<long long>> best(by_weight.size() + 1,
                                   vector<long long>(limit + 1, INT32_MIN));
    best[0][0] = 0;
    int at = 1;
    for (auto &[w, items] : by_weight)
    {
        // sort items in reverse order by value
        std::sort(items.begin(), items.end(), std::greater<pair<int, int>>());
        for (int i = 0; i <= limit; i++)
        {
            best[at][i] = best[at - 1][i];
            int copies = 0;
            int type_at = 0;
            int curr_used = 0;
            long long profit = 0;
            // go through as many items until we run out of items or usable
            // weight
            while ((copies + 1) * w <= i && type_at < items.size())
            {
                copies++;
                profit += items[type_at].first;
                if (best[at - 1][i - copies * w] != INT32_MIN)
                {
                    best[at][i] = std::max(
                        best[at][i], best[at - 1][i - copies * w] + profit);
                }

                curr_used++;
                if (curr_used == items[type_at].second)
                {
                    curr_used = 0;
                    type_at++;
                }
            }
        }
        at++;
    }
    cout << *std::max_element(best.back().begin(), best.back().end()) << endl;
}
