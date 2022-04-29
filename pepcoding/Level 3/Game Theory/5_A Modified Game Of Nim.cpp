// Given an array of integers, two players Alice and Bob are playing a game where Alice can remove any  element from the array that are multiples of 3. Similarly, Bob can remove multiples of 5. The player who can't remove any element loses the game. The task is to find the winner of the game if Alice starts first and both play optimally.


#include "../header.h"

void solve()
{
    int n, count_3 = 0, count_5 = 0, count_3_5 = 0;
    cin >> n;
    int arr[n];
    rarr(arr, 0, n);

    for (int val : arr)
    {
        if (val % 3 == 0 && val % 5 == 0)
            count_3_5++;
        else if (val % 3 == 0)
            count_3++;
        else if (val % 5 == 0)
            count_5++;
    }

    if (count_3_5 == 0)
    {
        if (count_3 > count_5)
            cout << "ALICE\n";
        else if (count_5 > count_3)
            cout << "BOB\n";
    }
    else if (count_3_5 != 0)
    {
        count_3 += 1;
        if (count_3 > count_5)
            cout << "ALICE\n";
        else if (count_5 > count_3)
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