// 1. You are given two integers N and M, and an array(arr) of numbers with length M.
// 2. N represents the total number of tasks assigned to a group of 5 students.
// 3. Out of these five students, three students completed M number of tasks of their choices and left the group.
// 4. Tasks completed by these students are represented by the given array.
// 5. Now, the remaining two students(s1 and s2) have to complete all the remaining tasks.
// 6. They decided to complete the remaining tasks in an alternate way -
//    First of the remaining tasks will be completed by s1
//    Second of the remaining tasks will be completed by s2
//    Third of the remaining tasks will be completed by s1.. and so on.    
// 7. You have to find the tasks that s1 and s2 have to complete.


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
