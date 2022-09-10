// https://leetcode.com/problems/avoid-flood-in-the-city/

#include "../header.h"

//! not tested please test the code...
vi solution(vi &rains)
{
    unordered_map<int, int> lastRain;
    set<int> dryDay;
    int n = rains.size();
    vi ans(n, 1);

    for (int i = 0; i < n; i++)
    {
        int x = rains[i];
        if (x == 0)
            dryDay.insert(x);
        else
        {
            if (lastRain.count(x) == false)
                lastRain[x] = i;
            else
            {
                int lstDay = lastRain[x];
                cout << "llloo";
                auto itr = dryDay.upper_bound(lstDay);
                if (itr == end(dryDay))
                    return {};
                int dryThisDay = *itr;

                ans[dryThisDay] = x;
                dryDay.erase(dryThisDay);
                lastRain[x] = i;
            }
            ans[i] = -1;
        }
    }
    return ans;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    test(t)
    {
        int n;
        cin >> n;
        vi arr(n);
        rarr(arr, 0, n);
        cout << "\n============================================\n";
        vi res = solution(arr);
        parr(res, res.size());
        cout << "\n============================================\n";
    }

    return 0;
}

/*
6
1 2 0 0 2 1
*/