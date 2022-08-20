// 1. You are given an array of n distinct integers.
// 2. You have to divide these n integers into k non-empty subsets such that sum of integers of every
//      subset is same.
// 3. If it is not possible to divide, then print "-1".

// Note -> Check out the question video and write the recursive code as it is intended without
//                changing signature. The judge can't force you but intends you to teach a concept.

#include "../header.h"

int counter = 0;
void solution(vi &arr, int vidx, int n, int k, vi &subSetSum, int ssssf, vvi &res)
{
    if (vidx == arr.size())
    {
        if (ssssf == k)
        {
            bool flag = true;
            for (int i = 0; i < subSetSum.size() - 1; i++)
                if (subSetSum[i] != subSetSum[i + 1])
                {
                    flag = false;
                    break;
                }

            if (flag == true)
            {
                for (auto partition : res)
                {
                    cout << "[";
                    for (int ele : partition)
                        cout << ele << " ";
                    cout << "]";
                }
                cout << endl;
            }
        }
        return;
    }

    for (int i = 0; i < res.size(); i++)
    {
        if (res[i].size() > 0)
        {
            res[i].pb(arr[vidx]);
            subSetSum[i] += arr[vidx];
            solution(arr, vidx + 1, n, k, subSetSum, ssssf, res);

            subSetSum[i] -= arr[vidx];
            res[i].pop_back();
        }

        else
        {
            res[i].pb(arr[vidx]);
            subSetSum[i] += arr[vidx];
            solution(arr, vidx + 1, n, k, subSetSum, ssssf + 1, res);

            subSetSum[i] -= arr[vidx];
            res[i].pop_back();
            break;
        }
    }
}

void solve()
{
    int n, k = 0, sum = 0;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);

    cin >> k;
    vi subSetSum(k);
    vvi res(k);

    for (int val : arr)
        sum += val;
    if (k == 1)
    {
        cout << "[";
        for (int val : arr)
            cout << val << " ";
        cout << "]";
    }
    else if (k > n || sum % k != 0)
        cout << "-1";
    else
        solution(arr, 0, n, k, subSetSum, 0, res);
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
6
1 2 3 4 5 6
3
*/