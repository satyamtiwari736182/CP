// Mr. Pepcoder has an array A, and his Friend love to do operations on the
// array. The operations can be a query or an update.

// For each query the Friend say two indices l and r , and their father answers back with the sum
// of the elements from indices l to r (both included).

// When there is an update, the friend says an index i and a value x , and Pepcoder will add x to
// ith index of array (so the new value of arr[i]  is arr[i] + x ).

// Because indexing the array from zero is too obscure for children, all indices start from 1.

#include "../header.h"

vi ftree, arr;

void update(int idx, int val)
{
    while (idx < ftree.size())
    {
        ftree[idx] += val;
        idx += idx & -idx;
    }
}

void buildFtree() // takes " nlogn "  time.
{
    for (int i = 1; i < arr.size(); i++)
        update(i, arr[i]);
}

int query(int idx) // logn per query
{
    int sum = 0;
    while (idx > 0)
    {
        sum += ftree[idx];
        idx -= idx & -idx;
    }
    return sum;
}

//!=========================================
// building fenwick tree in O(n) time complexity.
vi prefixarr;
void prefixSum()
{
    prefixarr.resize(arr.size());
    for (int i = 1; i < arr.size(); i++)
        prefixarr[i] = prefixarr[i - 1] + arr[i];
}

void buildftree()
{
    prefixSum();
    for (int i = 1; i < ftree.size(); i++)
    {
        int idx = i - (i & -i);
        ftree[i] = prefixarr[i] - prefixarr[idx];
    }
}
//!=========================================

void solve()
{
    int n;
    cin >> n;
    arr.resize(n + 1);
    ftree.resize(n + 1);
    rarr(arr, 1, arr.size());
    // fenwick tree

    // buildFtree();// O(nlogn)
    buildftree(); // O(n)

    // Query
    int q;
    cin >> q;
    test(q)
    {
        char type;
        cin >> type;
        if (type == 'q')
        {
            int left, right;
            cin >> left >> right;
            int ans = query(right) - query(left - 1);
            cout << ans << "  **\n";
        }
        else if (type == 'u')
        {
            int idx, val;
            cin >> idx >> val;
            int delta = -arr[idx] + val;
            update(idx, delta);
        }
    }
}

int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    // cin >> t;
    test(t)
    {
        solve();
        cout << "\n------------------------------\n";
    }

    return 0;
}

// 10
// 1 23 4 10 24 33 -1 -9 7 4
// 6
// q 2 5
// q 1 9
// u 3 -2
// q 4 5
// u 6 10
// q 4 9