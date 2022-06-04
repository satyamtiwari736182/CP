// 1. Given two non-negative integers, num1 and num2 represented as string.
// 2. Return the sum of num1 and num2 as a string.
// 3. You must solve the problem without using any built-in library for handling large integers (such as BigInteger). 
// 4. You must also not convert the inputs to integers directly.


#include "../header.h"

void solve()
{
    string num1, num2, num3 = "";

    cin >> num1 >> num2;
    int i = num1.length() - 1, j = num2.length() - 1, carry = 0;

    while (i >= 0 || j >= 0 || carry != 0)
    {
        int ival = i >= 0 ? num1[i] - '0' : 0;
        int jval = j >= 0 ? num2[j] - '0' : 0;
        i--, j--;

        int sum = ival + jval + carry;
        num3 = to_string(sum % 10) + num3;
        carry = sum / 10;
    }

    cout << num1 << " + " << num2 << " = " << num3 << endl;
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

1234 798

*/
