// You have a RecentCounter class which counts the number of recent requests within a certain time frame.

// Implement the RecentCounter class:
// 1. RecentCounter() Initializes the counter with zero recent requests.
// 2. int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, and returns the number of requests that has happened in the past 3000 milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].

// It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.

#include "../header.h"

queue<int> que;

int ping(int timeAt)
{
    que.push(timeAt);
    int strtTime = timeAt - 300;
    while (que.front() < strtTime)
        que.pop();
    return que.size();
}

void solve()
{
    while (1)
    {
        int pingTime;
        cin >> pingTime;
        cout << "total Ping: " << ping(pingTime) << endl;
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
1
100
3001
3002
*/
