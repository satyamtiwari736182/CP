#include "../header.h"

int solve(vi &arr)
{
    int ans = 0;
    sort(all(arr));
    map<int, int> hashmap;
    for (int val : arr)
        hashmap[val]++;

    for (auto pr : hashmap)
    {
        int chain_len = pr.fs + 1;
        int count = pr.se;
        ans += (count / chain_len) * chain_len;
        ans += count % chain_len ? chain_len : 0;
        // cout<<pr.fs<<" -> "<<pr.se<<endl;
    }

    return ans;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    test(t)
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

// 3

// 5
// 1 0 1 0 0

// 9
// 2 2 3 1 0 2 2 3 1

// 33
// 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 0 0 1 1 1