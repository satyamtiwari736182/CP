// 1. You are given three numbers A, B, and X.
// 2. You have to print all-powerful numbers that have value less than or equal to X.
// 3. A number is powerful if it is equal to x^i + y^j for i >= 0 and j >= 0.

#include "../header.h"

vi solve(int x, int y, int bound)
{
    set<int> hashset;
    for (int i = 1; i < bound; i *= x)
    {
        for (int j = 1; i + j <= bound; j *= y)
        {
            hashset.insert(i + j);
            if (y == 1)
                break;
        }
        if (x == 1)
            break;
    }
    return vi(all(hashset));
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    test(t)
    {
        int x, y, bound;
        cin >> x >> y >> bound;

        cout << "\n============================================\n";
        vi res = solve(x, y, bound);
        for (int val : res)
            cout << val << " ";
        cout << "\n============================================\n";
    }

    return 0;
}

// 2 3 10