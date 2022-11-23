#include "./header.h"
// #define ONLINE_JUDGE cout << "Provide input pls!!\n"
void solve()
{
    // int x = 90;
    // vi arr(7);
    // rarr(arr, 0, 7);
    // parr(arr, 7);
    // _print(arr);
    // cerr << "All done!!\n";
    map<char, int> mp;
    for (int i = 0; i < 4; i++)
    {
        int y;
        char x;
        cin >> x >> y;
        mp.insert({x, y});
    }
    _print(mp);
}

int main()
{
    fastio();
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    solve();
    return 0;
}