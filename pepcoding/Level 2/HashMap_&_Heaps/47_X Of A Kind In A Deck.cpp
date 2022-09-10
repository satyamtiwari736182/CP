// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/


#include "../header.h"

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int solve(vi &deck)
{
    unordered_map<int, int> fmap;
    for (int val : deck)
        fmap[val]++;
    int ans = 0;

    for (auto pr : fmap)
        ans = gcd(ans, pr.se);
    if (ans >= 2)
        return true;
    return false;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    test(t)
    {
        int n;
        cin >> n;
        vi arr(n);
        rarr(arr, 0, n);

        cout << "\n============================================\n";
        cout << solve(arr);
        cout << "\n============================================\n";
    }

    return 0;
}

/*
8
1 2 3 4 4 3 2 1

8
1 1 1 2 2 2 3 3
*/