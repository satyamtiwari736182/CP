// 1. Question will be provided with "n" meeting-schedules. A meeting-schedule is defined as (sp,ep) i.e. sp --> starting point &  ep --> ending point of an meeting. Some meeting-schedules may or maynot overlap each other.
// 2. MeetingIntervals[i] = [startingPointi,endingPointi]
// 3. A meeting-schedule represents meeting time(i.e. starting time & ending time).

// Task is to "figure out, whether is it possible to attend all meetings or not".

#include "../header.h"

bool meetingRooms(vvi &meetingInfo)
{
    int n = meetingInfo.size();
    sort(all(meetingInfo), [&](vi a, vi b)
         { return a[0] < b[0]; });

    int endTime = meetingInfo[0][1];
    for (int idx = 1; idx < n; idx++)
    {
        if (meetingInfo[idx][0] < endTime)
            return false;
        else
            endTime = meetingInfo[idx][1];
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vvi meetingInfo(n, vi(2));
    rmatrix(meetingInfo, n, 2);
    cout << "--------------------" << endl;
    // pmatrix(meetingInfo, 2, n);
    cout << meetingRooms(meetingInfo);
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
