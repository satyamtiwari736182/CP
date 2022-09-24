// 1. You are given an array of distinct integers.
// 2. You have to print all pairs of integers in the array whose XOR value is minimum.


#include "../header.h"

vector<string> sol(vi &arr)
{
    vector<string> res;
    sort(all(arr));
    int minXor = INT_MAX;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int Xor = arr[i] ^ arr[i + 1];
        if (Xor < minXor)
        {
            minXor = Xor;
            res.clear();
            res.pb(to_string(minXor));
            res.pb(to_string(arr[i]) + "-" + to_string(arr[i + 1]));
        }
        else if (Xor == minXor)
            res.pb(to_string(arr[i]) + "-" + to_string(arr[i + 1]));
    }
    return res;
}

int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;
    vi arr;
    rvarr(arr, 0, n);
    cout << "\n========================================\n";
    vector<string> pairs = sol(arr);

    for (auto pr : pairs)
        cout << pr << ", ";

    // 1, 6 - 7, 8 - 9, 14 - 15,
    // cout << (6 ^ 7) << "\t" << (8 ^ 9) << "\t" << (14 ^ 15) << endl;
    cout << "\n========================================\n";
    return 0;
}

// 11
// 5 15 7 3 18 9 8 16 12 14 6