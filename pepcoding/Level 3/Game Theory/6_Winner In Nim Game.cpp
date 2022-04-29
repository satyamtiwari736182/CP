// Given an array of integers, two players Alice and Bob are playing a game where Alice can remove any element from the array.If the bitwise XOR of all remaining elements equals 0 after removal of selected element, then that player looses.Find out winner if both of the players play optimally. Alice starts the game first. In case case one-element in array consider its value as the XOR of array

#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    rarr(arr, 0, n);

    int nimSum = 0;
    for (int val : arr)
        nimSum ^= val;

    if (nimSum == 0)
        cout << "ALICE\n";
    else
    {
        if (n % 2 == 0)
            cout << "ALICE\n";
        else
            cout << "BOB\n";
    }
}

int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    // cin >> t;
    test(t)
    {
        solve();
        cout << "\n------------------------------\n";
    }

    return 0;
}

// 5
// 15 6 9 10 20