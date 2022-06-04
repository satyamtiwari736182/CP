// 1. Given two non-negative integers num1 and num2 represented as strings.
// 2. Return the product of num1 and num2, also represented as a string.
// 3. Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include "../header.h"

void solve()
{
    string num1, num2, num3 = "";

    cin >> num1 >> num2;
    int n1 = num1.length(), n2 = num2.length();
    vi res(n1 + n2);
    int i = n2 - 1, pf = 0;

    while (i >= 0)
    {
        int ival = num2[i] - '0';
        i--;
        int j = n1 - 1;
        int k = res.size() - 1 - pf;
        int carry = 0;

        while (j >= 0 || carry != 0)
        {
            int jval = j >= 0 ? num1[j] - '0' : 0;
            j--;

            int prod = ival * jval + carry + res[k];
            res[k] = prod % 10, carry = prod / 10;
            k--;
        }
        pf++;
    }
    cout << endl;
    parr(res, res.size());
    cout << endl;
    int flag = 0;
    for (int val : res)
    {
        if (val == 0 && flag == false)
            continue;
        flag = true;
        num3 = num3 + to_string(val);
    }

    // for (int i = n2 - 1; i >= 0; i--)
    // {
    //     for (int j = n1 - 1; j >= 0; j--)
    //     {
    //         int res = (num1[j] - '0') * (num2[i] - '0') + carry;
    //         int sum = res % 10, carry = res / 10;

    //     }
    //     cout << endl;
    // }

    cout << num1 << " * " << num2 << " = " << num3 << endl;
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

123 456

*/
