// Design a hit counter which counts the number of hits received in the past 5 minutes (i.e., the past 300 seconds).

// Your system should accept a timestamp parameter (in seconds granularity), and you may assume that calls are being made to the system in chronological order (i.e., timestamp is monotonically increasing). Several hits may arrive roughly at the same time.

// Implement the HitCounter class:

// HitCounter() Initializes the object of the hit counter system.
// void hit(int timestamp) Records a hit that happened at timestamp (in seconds). Several hits may happen at the same timestamp.
// int getHits(int timestamp) Returns the number of hits in the past 5 minutes from timestamp (i.e., the past 300 seconds).

#include "../header.h"

class HitCounter
{
private:
    queue<int> que;

public:
    void hit(int timestamp)
    {
        que.push(timestamp);
        int start = timestamp - 300 + 1;
        while (que.size() && que.front() < start)
            que.pop();
    }

    int getHits(int timestamp)
    {
        int start = timestamp - 300 + 1;
        while (que.size() && que.front() < start)
            que.pop();
        return que.size();
    }
};

void solve()
{
    string str;
    cin >> str;
    HitCounter hitCnt;
    while (str != "exit")
    {
        int timestamp;
        cin >> timestamp;
        if (str == "hit")
            hitCnt.hit(timestamp);
        else if (str == "getHits")
            cout << hitCnt.getHits(timestamp) << endl;
        cin >> str;
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
hit 1
hit 2
hit 3
getHits 4
hit 300
getHits 300
getHits 301
exit
*/