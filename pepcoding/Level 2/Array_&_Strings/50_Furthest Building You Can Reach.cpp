// https://leetcode.com/problems/furthest-building-you-can-reach/

#include "../header.h"

int futhestBuilding(vi &h, int b, int l)
{
    priority_queue<int, vi, greater<int>> pqueue;
    for (int i = 0; i < h.size() - 1; i++)
    {
        int diff = h[i + 1] - h[i];
        if (diff > 0)
            pqueue.push(diff);
        if (pqueue.size() > l)
            b -= pqueue.top(), pqueue.pop();
        if (b < 0)
            return i;
    }
    return h.size() - 1;
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    int brick, laddar;
    cin >> brick >> laddar;
    cout << "--------------------" << endl;
    cout << futhestBuilding(arr, brick, laddar);
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
4
14 3 19 3
17 0
------------
9
4 12 2 7 3 18 20 3 19
10 2
*/
