// 1. IntervalList & a newInterval will be given as input.
// 2. IntervalList is a sequence of sorted(on the basis of start time) & non-overlapping intervals.
// 3. any interval[i] (from IntervalList) = [startTime,endTime].
// 4. a newInterval will also be passed as input.
// Task is to "Insert this newInterval to the given sorted IntervalList".
// NOTE : Inserting this newInterval may lead to merging of intervals.

// Example 1 :
//     IntervalList = [[1,5][8,10]]
//     newInterval = [3,8]
//     OUTPUT : [[1,10]].
//     Explanation : after inserting newInterval (3,8) ,every interval can now be merged to (1,10).

// Example 2 :
//     IntervalList = [[1,5][8,10]]
//     newInterval = [3,6]
//     OUTPUT : [[1,6][8,10]].

// Example 3 :
//     IntervalList = [[3,5][8,10]]
//     newInterval = [1,2]
//     OUTPUT : [[1,2][3,5][8,10]].

// Example 4 :
//     IntervalList = []
//     newInterval = [3,8]
//     OUTPUT : [[3,8]].

#include "../header.h"

vvi solve(vvi &lst, vi interval)
{
    vvi res;
    int n = lst.size(), i = 0;
    vi lastInterval;

    while (i < n)
    {
        if (lst[i][0] < interval[0])
            res.pb(lst[i]), lastInterval = lst[i], i++;
        else
            break;
    }

    if (res.size() == 0 || interval[0] > lastInterval[1])
        res.pb(interval), lastInterval = interval;
    else
        res[res.size() - 1][1] = max(lastInterval[1], interval[1]);

    while (i < n)
    {
        lastInterval = *(res.end() - 1);
        if (lastInterval[1] >= lst[i][0])
            res[res.size() - 1][1] = max(lastInterval[1], lst[i][1]);
        else
            res.pb(lst[i]);
        i++;
    }
    return res;
}

int main()
{
    cout << "hello world!\n";
    int n;
    cin >> n;
    vvi lst(n);
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        lst[i] = {s, e};
    }
    int s, e;
    cin >> s >> e;
    vvi res = solve(lst, {s, e});
    cout << "\n";
    pmatrix(res, res.size(), 2);
}

// 5
// 1 5
// 7 9
// 10 13
// 16 19
// 20 25
// 12 20