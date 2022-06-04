// 1. You are given a number in form of String. 
// 2. You can swap two digits at most once to get the maximum valued number in that string.
// 3. Return the maximum valued number you can get in form of string.


#include "../header.h"

void solve()
{
    string num;
    cin >> num;
    vi lastIdx(10);

    // 1. pepare the last index of digit
    for (int i = 0; i < num.length(); i++)
        lastIdx[num[i] - '0'] = i;

    // 2.find-out position for swapping
    bool flag = false;
    for (int i = 0; i < num.length(); i++)
    {
        int digit = num[i] - '0';
        for (int j = 9; j > digit; j--)
            if (i < lastIdx[j])
            {
                swap(num[i], num[lastIdx[j]]);
                flag = true;
                break;
            }

        if (flag == true)
            break;
    }

    cout << num << endl;
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
2736
*/

