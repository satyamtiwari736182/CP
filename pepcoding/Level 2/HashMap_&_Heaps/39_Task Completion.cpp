#include "../header.h"

vector<vi> solve(vi &arr, int n)
{
    vi stud1, stud2, task(n + 1);
    for (int val : arr)
        task[val] = 1;
    int flag = 1;
    for (int i = 1; i <= n; i++)
    {
        if (task[i] == 0)
        {
            if (flag == 1)
            {
                stud1.pb(i);
                flag = 2;
            }
            else if (flag == 2)
            {
                stud2.pb(i);
                flag = 1;
            }
            task[i] = 1;
        }
    }
    return {stud1, stud2};
}

int main()
{
    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    test(t)
    {
        int n, m;
        cin >> n >> m;
        vi arr;
        rvarr(arr, 0, m);

        cout << "\n============================================\n";
        auto ans = solve(arr, n);
        for (vi stud : ans)
        {
            for (int val : stud)
                cout << val << " ";
            cout << endl;
        }

        cout << "\n============================================\n";
    }

    return 0;
}

// 1

// 15 6
// 2 5 6 7 9 4
