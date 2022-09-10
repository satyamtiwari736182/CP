// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

#include "../header.h"

string getHappyString(int n, int k)
{
    int tot = 3;
    for (int i = 1; i < n; i++)
        tot *= 2;
    if (tot < k)
        return "";
    int calls = 3;
    k--;
    int pcall = -1;
    string ans = "";
    while (n-- > 0)
    {
        int spart = (tot / calls);
        int ncall = (k / spart);
        if (ncall == 0)
        {
            if (pcall == 0)
                pcall = 1;
            else
                pcall = 0;
        }
        else if (ncall == 1)
        {
            if (pcall == -1 || pcall == 2)
                pcall = 1;
            else
                pcall = 2;
        }
        else
            ncall = 2;
        ans += (char)('a' + pcall);
        tot = spart;
        k -= spart * ncall;
        calls = 2;
    }
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    cout << "--------------------" << endl;
    cout << getHappyString(n, k);
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
3 8
5 8
*/
