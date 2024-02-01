#include "./header.h"
int solver(int e, int f)
{
    if (f == 0 || f == 1)
        return f;
    if (e == 0)
        return 0;
    if (e == 1)
        return f;

    int ans = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
        int tempAns = 1 + max(solver(e - 1, k - 1), solver(e, f - k));
        ans = min(ans, tempAns);
    }
    return ans;
}
void solve()
{
    int f, e;
    cin >> e >> f;
    cout << solver(e, f) << endl;
}

int main()
{
    cout << "hello\n";
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}