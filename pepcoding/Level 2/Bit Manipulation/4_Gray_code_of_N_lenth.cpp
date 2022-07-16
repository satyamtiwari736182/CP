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
