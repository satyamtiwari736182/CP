// 1: On a single-threaded CPU, we execute a program containing n functions. Each function has a unique ID between 0 and n-1.
// 2: You are required to find the total execution time of each function.
// 3: You are given len number of logs, where logs[i] represents the ith log message formatted as a string "{function_id}:{"start" | "end"}:{timestamp}", telling start or end time of function with id function_id.

// Note that a function can be called multiple times, possibly recursively.

#include "../header.h"

class Pair
{
public:
    int pid, st, ct;
    Pair(int id, int st, int ct) : pid(id), st(st), ct(ct) {}
};

void solve()
{
    int process_cnt, log_cnt;
    cin >> process_cnt >> log_cnt;
    vs logs;
    string val, str;
    stack<Pair> stk;
    vi timeP(process_cnt);

    test(log_cnt)
    {
        fflush(stdin);
        getline(cin, str);
        str_to_tok(str, ':', logs, val);

        if (logs[1] == "start")
            stk.push(Pair(stoi(logs[0]), stoi(logs[2]), 0));
        else
        {
            Pair pr = stk.top();
            stk.pop();
            int interval = stoi(logs[2]) - pr.st + 1;
            timeP[pr.pid] += interval - pr.ct;

            if (!stk.empty())
                stk.top().ct += interval;
        }

        logs.clear();
        fflush(stdout);
    }
    parr(timeP, timeP.size());
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

2
4
0:start:0
1:start:2
1:end:5
0:end:6

*/