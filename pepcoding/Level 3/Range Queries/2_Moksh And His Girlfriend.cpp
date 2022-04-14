// Recently Moksh(HR of Pepcoding) invented a serum which can increase height of plant by 1 unit. Moksh's girlfriend birthday is next month.
// He is planning something amazing as a gift for her.His girlfriend's favourite Integer is M.

// Initially Moksh has N (1 to N) no. of beautiful Rose plants, Each plant can have an Integer height,Initially the height of each plant is zero.
// Subhesh gives Moksh Q number of operations,In each operation Moksh got two integer start and end and he increases the height of all the plants between start and end position (including start and end) by 1.
// As Moksh wasn't happy with the pattern of height of the plants formed, He went to Rajneesh and asked him to remove any 1 operation from the Q operations such that the count of plants with height M is maximum possible.
// Output the maximum possible number of plants with height M.

// Expected Complexity : O(n+q)



#include "../header.h"
void prefixSum(vi &arr)
{
    for (int i = 1; i < arr.size(); i++)
        arr[i] += arr[i - 1];
}

vi prefixCount(vi &arr, int val)
{
    int n = arr.size();
    vi prefixcount(n);
    prefixcount[0] = arr[0] == val ? 1 : 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == val)
            prefixcount[i] += prefixcount[i - 1] + 1;
        else
            prefixcount[i] = prefixcount[i - 1];
    }
    return prefixcount;
}
int solve()
{
    int n, q, m;
    cin >> n >> q >> m;
    vi arr(n + 1);
    vector<pi> query;
    test(q)
    {
        int left, right, val = 1;
        cin >> left >> right;
        query.pb({left, right});
        arr[left] += val;
        arr[right + 1] += -val;
    }
    prefixSum(arr);
    vi m_count = prefixCount(arr, m);
    vi m_1_count = prefixCount(arr, m + 1);

    int maxMcount = m_count[n - 1];
    int count = INT_MIN;

    for (int i = 0; i < query.size(); i++)
    {
        int left = query[i].fs;
        int right = query[i].se;
        // total_cnt-loss+gain;
        int new_m_cnt = maxMcount - (m_count[right] - m_count[left - 1]) + (m_1_count[right] - m_1_count[left - 1]);
        count = max(count, new_m_cnt);
    }
    // parr(arr, arr.size());
    // cout << endl;
    // parr(m_count, arr.size());
    // cout << endl;
    // parr(m_1_count, arr.size());
    return count;
}

int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    // cin >> t;
    test(t)
    {
        cout << solve();
        cout << "\n------------------------------\n";
    }

    return 0;
}

// 10 3 2
// 2 6
// 4 9
// 1 4