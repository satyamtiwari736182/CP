// Description :
// 1. Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
// 2. In Pascal's triangle, each number is the sum of the two numbers directly above OR it is also a pattern which can be made from combination maths
// 3. For More clearance, watch video till explanation of question.
// eg.
// row 0 -> 1
// row 1 -> 1 1
// row 2 -> 1 2 1
// row 3 -> 1 3 3 1
// row 4 -> 1 4 6 4 1

#include "../header.h"
vi pascalRow(int i)
{
    // write your code here
    vi res;
    int val = 1;
    for (int j = 0; j <= i; j++)
        res.pb(val), val = (val * (i - j)) / (j + 1);
    return res;
}

void solve()
{
    int n;
    cin >> n;

    cout << "--------------------" << endl;
    vi res = pascalRow(n);
    for (int val : res)
        cout << val << " ";
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

// 4