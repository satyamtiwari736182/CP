#include "../header.h"

void dfs(int i, int n)
{
    if (i > n)
        return;
    cout << i << endl;
    for (int j = 0; j < 10; j++)
        dfs(10 * i + j, n);
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 9; i++)
        dfs(i, n);
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
14
*/