// 1. Question will be provided with "n" meeting-schedules. A meeting-schedule is defined as (sp,ep) i.e. sp --> starting point &  ep --> ending point of an meeting. Some meeting-schedules may or maynot overlap each other.
// 2. MeetingIntervals[i] = [startingPointi,endingPointi]
// 3. A meeting-schedule represents meeting time(i.e. starting time & ending time).

// Task is to "figure out, how many minimum number of meeting rooms are required to schedule all meetings?".

// Example 1 :
//     Input : [[1,3],[2,4],[6,8],[10,14],[7,9]]
//     Output : 2
//     Explanation : Two meetings are scheduled are scheduled at a time i.e. we require atleast 2 meeting rooms to schedule meetings.

// Example 2 :
//     Input : [[1,3],[3,10],[12,20]]
//     Output : 1
//     Explanation : There is no meeting-schedule overlap i.e. 1 meetng room can do the trick.
// Example 3 :
//     Input : [[1,3],[5,8],[10,19],[15,20],[9,9]]
//     Output : 2.

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
