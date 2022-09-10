// 1. Pepcoder is wishing to give offerings to all the temples along a mountain range.
// 2. The temples are located in a row at different heights.
// 3. You have to find the minimum number of offerings such that these conditions are fulfilled -
//     -> If two adjacent temples are at different heights, then the temple which is situated at greater height should receive more offerings.
//     -> If two adjacent temples are at the same height, then their offerings relative to each other does not matter.

#include "../header.h"

int totalOffering(vi &heights)
{
    vi leftSide(heights.size()), rightSide(heights.size());
    leftSide[0] = 1;
    for (int i = 1; i < heights.size(); i++)
    {
        if (heights[i] > heights[i - 1])
            leftSide[i] = leftSide[i - 1] + 1;
        else
            leftSide[i] = 1;
    }

    rightSide[heights.size() - 1] = 1;
    for (int i = heights.size() - 2; i >= 0; i--)
    {
        if (heights[i] > heights[i + 1])
            rightSide[i] = rightSide[i + 1] + 1;
        else
            rightSide[i] = 1;
    }

    int ans = 0;
    for (int i = 0; i < heights.size(); i++)
        ans += max(leftSide[i], rightSide[i]);

    return ans;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);

    cout << "\n------------\n";
    cout << totalOffering(arr) << endl;

    //------------------------------------------------------

    return 0;
}

/*
6
1 3 2 5 2 1
*/
