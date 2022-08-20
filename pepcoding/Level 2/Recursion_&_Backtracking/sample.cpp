#include "../header.h"

string maximum;
void findMaximum(string str, int k)
{
    if (stoi(str) > stoi(maximum))
        maximum = str;
    if (k == 0)
        return;
    for (int i = 0; i <= str.length() - 2; i++)
        for (int j = i + 1; j < str.length(); j++)
            if (str[j] > str[i])
            {
                swap(str[i], str[j]);
                findMaximum(str, k - 1);
                swap(str[i], str[j]);
            }
}

void solve()
{
    string str;
    cin >> str;
    int k;
    cin >> k;
    maximum = str;
    findMaximum(str, k);
    cout << maximum << endl;
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
1234567
2
*/