// 1. There are some rabbits in the forest and each rabbit has some color.
// 2. Some(possibly all) rabbits are selected from them and they tell you about the number of other rabbits having the same color as them.
// 3. You are given an array(arr) that contains the answers of all selected rabbits.
// 4. You have to find the minimum number of rabbits that could be in the forest.

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