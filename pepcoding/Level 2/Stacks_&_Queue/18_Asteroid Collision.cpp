// 1. You are given an array asteroids of integers representing asteroids in a row.
// 2. For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left).
// 3. Each asteroid moves at the same speed.
// 4. You need to find out the state of the asteroids after all collisions.
// 5. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

#include "../header.h"

void solve()
{
    int n;
    fflush(stdin);
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    stack<int> stk;

    for (int asteroid : arr)
    {
        if (asteroid > 0)
            stk.push(asteroid);
        else
        {
            while (!stk.empty() && stk.top() > 0 && stk.top() < -asteroid)
                stk.pop();
            if (!stk.empty() && stk.top() > 0 && stk.top() == -asteroid)
                stk.pop();
            else if (!stk.empty() && stk.top() > 0 && stk.top() > -asteroid)
                ;
            else
                stk.push(asteroid);
        }
    }

    cout << stk.size() << endl;
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}

int main()
{
    cout << "\nHello world\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();

    return 0;
}

/*

7
3 2 -1 3 -3 3 -4

*/