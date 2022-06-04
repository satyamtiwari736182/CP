#include "../header.h"

int calculator(string str)
{
    stack<int> stk;
    int sum = 0, sign = 1;

    for (char ch : str)
    {
        if (isdigit(ch) == true)
        {
            int val = 0;
            while (1)
                ;
        }
    }

    return sum;
}

void solve()
{
    string str;
    cin >> str;

    fflush(stdin);
    int res = calculator(str);
    cout << res << endl;
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
