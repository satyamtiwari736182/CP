// 1. You are given a number n, representing the number of time-intervals.
// 2. In the next n lines, you are given a pair of space separated numbers.
// 3. The pair of numbers represent the start time and end time of a meeting (first number is start time and second number is end time)
// 4. You are required to merge the meetings and print the merged meetings output in increasing order of start time.

// E.g. Let us say there are 6 meetings
// 1 8
// 5 12
// 14 19
// 22 28
// 25 27
// 27 30

// Then the output of merged meetings will belongs
// 1 12
// 14 19
// 22 30

// Note -> The given input maynot be sorted by start-time.

#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    vector<pi> vec, res;

    while (n-- > 0)
    {
        int st, en;
        cin >> st >> en;
        vec.pb({st, en});
    }

    sort(all(vec), [=](const pi a, const pi b)
         { return a.fs < b.fs; });

    stack<pi> stk;
    stk.push(vec[0]);
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i].fs >= stk.top().fs && vec[i].fs <= stk.top().se)
        {
            pi temp = stk.top();
            stk.pop();
            temp.se = max(vec[i].se, temp.se);
            stk.push(temp);
        }
        else
            stk.push(vec[i]);
    }

    while (!stk.empty())
        res.pb(stk.top()), stk.pop();
    cout << endl;

    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i].fs << " " << res[i].se << endl;
}

int main()
{
    cout << "Hello world!\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();
    return 0;
}

/*
6
1 8
5 12
14 19
22 28
25 27
27 30
*/