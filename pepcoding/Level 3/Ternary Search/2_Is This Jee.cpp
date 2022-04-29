// https://www.codechef.com/problems/ICM2003

// Minimise f(x), where f(x) = (x ^ 2 + bx + c) / sin(x), 0 < x < pi / 2

#include "../header.h"

int b = 0, c = 0;
lld func(lld x)
{
    lld ans = (x * x + b * x + c) / sin(x);
    return ans;
}

lld minimise_func()
{
    lld left = 0, right = PI / 2;
    while (right - left > 0.000001)
    {
        lld mid1 = left + (right - left) / 3;
        lld mid2 = right - (right - left) / 3;
        lld value1 = func(mid1);
        lld value2 = func(mid2);


        // 1.lies in left part
        if (value1 < value2)
            right = mid2;

        // 2.lies in right part
        else if (value1 > value2)
            left = mid1;

        // 3.lies in-between left and right
        else
        {
            left = mid1;
            right = mid2;
        }
    }

    return func(left);
}

void solve()
{
    cin >> b >> c;

    lld x = minimise_func();
    cout << x << endl;
}
int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    cin >> t;
    test(t)
    {
        solve();
        cout << "\n------------------------------\n";
    }

    return 0;
}

/*
1
2 2
*/