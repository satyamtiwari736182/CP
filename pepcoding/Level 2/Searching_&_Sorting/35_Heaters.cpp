// 1. Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.
// 2. Every house can be warmed, as long as the house is within the heater's warm radius range.
// 3. Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.
// 4. Notice that all the heaters follow your radius standard, and the warm radius will the same.

#include "../header.h"
pi binarySearch(int val, vi &arr)
{
    int low = 0, high = arr.size() - 1;
    pi pr = mp(-1, -1);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == val)
        {
            pr = {arr[mid], arr[mid]};
            break;
        }
        else if (val > arr[mid])
            pr.se = arr[mid], low = mid + 1;
        else
            pr.fs = arr[mid], high = mid - 1;
    }
    return pr;
}

int findRadius(vi &houses, vi &heater)
{
    sort(all(heater));
    int ans = 0;
    for (int i = 0; i < houses.size(); i++)
    {
        int housePosition = houses[i];
        pi pr = binarySearch(housePosition, heater); // justSmaller,justGreater
        int dist1 = pr.fs == -1 ? INT_MAX : housePosition - pr.fs;
        int dist2 = pr.se == -1 ? INT_MAX : housePosition - pr.se;
        ans = max(ans, min(dist1, dist2));
    }
    return ans;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        vi houses(n);
        rarr(houses, 0, n);
        cin >> m;
        vi heater(m);
        rarr(heater, 0, n);

        cout << "\n============================================\n";
        cout << findRadius(houses, heater);
        cout << "\n============================================\n";
    }
    return 0;
}

/*
15
4 4 4 4 3 4 4 4 4 2 4 4 3 3 3
*/

// 4
// 1 2 5 7
// 2
// 1 4