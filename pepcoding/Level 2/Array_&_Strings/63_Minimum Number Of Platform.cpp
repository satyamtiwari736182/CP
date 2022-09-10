// 1. We have arrival and departure times of all trains that reach a railway station. 
// 2. We have to find the minimum number of platforms required for the railway station so that no train is kept waiting.
// 3. Consider that all the trains arrive on the same day and leave on the same day. 
// 4. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. 
// 5. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.

#include "../header.h"

int findPlatform(vvi &trainInfo)
{
    vi arr = trainInfo[0], dep = trainInfo[1];
    sort(all(arr)), sort(all(dep));
    int i = 0, j = 0, n = arr.size();
    int maxTrain_cnt = 0, platform_cnt = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
            maxTrain_cnt++, i++;
        else
            maxTrain_cnt--, j++;
        platform_cnt = max(platform_cnt, maxTrain_cnt);
    }
    return platform_cnt;
}

void solve()
{
    int n;
    cin >> n;
    vvi trainInfo(2, vi(n));
    rmatrix(trainInfo, 2, n);
    cout << "--------------------" << endl;
    cout << findPlatform(trainInfo);
}

int main()
{
    cout << "\nHello world\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();

    return 0;
}

/*
6
0900 0940 0950 1100 1500 1800
0910 1200 1120 1130 1900 2000

*/
