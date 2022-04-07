#include "../header.h"

int solve(vector<vi> &arr, int target)
{
    int count = 0;
    map<int, int> hashmap;
    vi A = arr[0];
    vi B = arr[1];
    for (int a : A)
        for (int b : B)
            hashmap[a + b] = 1;
    A = arr[2];
    B = arr[3];
    for (int a : A)
        for (int b : B)
            if (hashmap.count(target - (a + b)) == 1)
                count++;
    return count;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    test(t)
    {
        int n, sum;
        vector<vi> arr(4);
        cin >> n;
        rvmatrix(arr, 4, n);
        cin >> sum;

        cout << "\n============================================\n";
        cout << solve(arr, sum);
        cout << "\n============================================\n";
    }

    return 0;
}

// 1

// 2
// 1 2
// -2 -1
// -1 2
// 0 2
// 0
