// 1. You are given two integers n and k, where n represents number of elements and k represents 
//      number of subsets.
// 2. You have to partition n elements in k subsets and print all such configurations.

// Note -> Check out the question video and write the recursive code as it is intended without 
//                changing signature. The judge can't force you but intends you to teach a concept.

#include "../header.h"

int counter = 0;
void solution(int i, int n, int k, int nos, vvi &res)
{
    if (i > n)
    {
        if (nos == k) // no. of set
        {
            counter++;
            cout << counter << ". ";
            for (auto Set : res)
            {
                cout << "[";
                for (int j = 0; j < Set.size(); j++)
                    cout << Set[j] << (j != Set.size() - 1 ? "," : "");
                cout << "] ";
            }
            cout << endl;
        }
        return;
    }
    for (int Set = 0; Set < res.size(); Set++)
    {
        if (res[Set].size() > 0)
        {
            res[Set].pb(i);
            solution(i + 1, n, k, nos, res);
            res[Set].pop_back();
        }

        else
        {
            res[Set].pb(i);
            solution(i + 1, n, k, nos + 1, res);
            res[Set].pop_back();
            break;
        }
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vvi res(k);
    solution(1, n, k, 0, res);
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
3 2
*/
