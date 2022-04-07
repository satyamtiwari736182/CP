// 1. You are given an array which represents heights of consecutive buildings.
// 2. You can move from the roof of a building to the roof of next adjacent building.
// 3. You need to find the maximum number of consecutive steps you can put forward such that you gain an increase in altitude with each step.

#include "../header.h"

int solve(vi &arr)
{
    int maxsteps = 0, tempcnt = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            tempcnt++;
            maxsteps = max(maxsteps, tempcnt);
        }
        else
            tempcnt = 0;
    }

    return maxsteps;
}
int main()
{
    cout << "\nHello world!" << endl;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr;
        rvarr(arr, 0, n);

        cout << "\n============================================\n";

        cout << solve(arr);

        cout << "\n============================================\n";
    }
    return 0;
}

// 2

// 7
// 1 4 5 2 3 2 4

// 13
// 1 4 5 7 6 2 4 5 6 8 9 10 20