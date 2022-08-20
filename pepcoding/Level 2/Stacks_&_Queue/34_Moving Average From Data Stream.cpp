// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

// Implement the MovingAverage class:
// 1. MovingAverage(int size) Initializes the object with the size of the window size.
// 2. double next(int val) Returns the moving average of the last size values of the stream.

#include "../header.h"

class MovingAverage
{
private:
    queue<int> que;
    int size, sum = 0;

public:
    MovingAverage(int sze) : size(sze) {}
    double next(int val)
    {
        sum += val;
        que.push(val);
        if (que.size() > size)
            sum -= que.front(), que.pop();
        double avg = ((double)sum) / que.size();
        return avg;
    }
};

void solve()
{
    int n;
    cin >> n;
    MovingAverage movAvg(n);
    while (1)
    {
        int val;
        cin >> val;
        cout << "Current Avg.: " << movAvg.next(val) << endl;
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
3
1
10
3
5
*/