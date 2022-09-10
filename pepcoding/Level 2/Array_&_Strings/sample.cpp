#include "../header.h"

int meetingRooms(vvi &intervals)
{
    int n = intervals.size();
    sort(all(intervals), [&](vi a, vi b)
         { return a[0] < b[0]; });

    priority_queue<int, vi, greater<int>> pque;
    for (auto interval : intervals)
    {
        if (pque.empty())
            pque.push(interval[1]);
        else if (pque.top() > interval[0])
            pque.push(interval[1]);
        else
            pque.pop(), pque.push(interval[1]);
    }

    return pque.size();
}

void solve()
{
    int n;
    cin >> n;
    vvi intervals(n, vi(2));
    rmatrix(intervals, n, 2);
    cout << "--------------------" << endl;
    // pmatrix(intervals, 2, n);
    cout << meetingRooms(intervals);
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
5
1 3
8 10
7 8
9 15
2 6

*/
