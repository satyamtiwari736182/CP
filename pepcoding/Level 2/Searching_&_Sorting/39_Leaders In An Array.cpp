// Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader.

#include "../header.h"

void leadersInarray(vi &arr)
{
    int prevLeader = INT_MIN;
    vi leader;

    for (int i = arr.size() - 1; i >= 0; i--)
        if (arr[i] >= prevLeader)
            leader.pb(arr[i]), prevLeader = arr[i];

    reverse(all(leader));
    for (int val : leader)
        cout << val << " ";
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr(n);
        rarr(arr, 0, n);

        cout << "\n============================================\n";
        leadersInarray(arr);
        cout << "\n============================================\n";
    }
    return 0;
}

/*
7
16 17 5 4 3 5 2
*/