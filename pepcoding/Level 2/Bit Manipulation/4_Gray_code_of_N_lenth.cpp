// 1. The gray code is a binary numeral system where two successive numbers differ in only one bit.
// 2. Given a non-negative integer n representing the total number of bits in the code, print the 
//      sequence of gray code. A gray code sequence must begin with 0.
 
//  Example:
//  Input: 2
//  Output: [0,1,3,2]
//  Explanation:
//  00 - 0
//  01 - 1
//  11 - 3
//  10 - 2
//  [0,2,3,1] is also a valid gray code sequence.
//  00 - 0
//  10 - 2
//  11 - 3
//  01 - 1

#include "../header.h"

vs sol(int n)
{
    vs res;
    if (n == 1)
    {
        res.pb("0");
        res.pb("1");
        return res;
    }
    vs rres = sol(n - 1);
    for (auto ans : rres)
    {
        res.pb("0" + ans);
        res.pb("1" + ans);
    }
    return res;
}

int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;

    cout << "\n========================================\n";
    vs res = sol(n);
    for (auto ans : res)
        cout << ans << endl;

    cout << "\n========================================\n";
    return 0;
}
