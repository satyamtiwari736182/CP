// 1. You are given an integer n, which represents n friends numbered from 1 to n.
// 2. Each one can remain single or can pair up with some other friend.
// 3. You have to print all the configurations in which friends can remain single or can be paired up.

// Note -> Check out the question video and write the recursive code as it is intended without
//                changing signature. The judge can't force you but intends you to teach a concept.

#include "../header.h"

int counter = 1;
void solution(int i, int n, bool *used, string asf)
{
    if (i > n)
    {
        cout << counter << ". " << asf << endl;
        counter++;
        return;
    }

    if (used[i] == true)
        solution(i + 1, n, used, asf);

    else
    {
        used[i] = true;
        solution(i + 1, n, used, asf + "(" + to_string(i) + ") ");
        for (int j = i + 1; j <= n; j++)
        {
            if (used[j] == false)
            {
                used[j] = true;
                solution(i + 1, n, used, asf + "(" + to_string(i) + "," + to_string(j) + ") ");
                used[j] = false;
            }
        }
        used[i] = false;
    }
}

void solve()
{
    int n;
    cin >> n;
    bool used[100000] = {0};
    solution(1, n, used, "");
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
*/

// 3