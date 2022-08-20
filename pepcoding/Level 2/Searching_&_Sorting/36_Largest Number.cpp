// Given a list of non-negative integers nums, arrange them such that they form the largest number.

// Note: The result may be very large, so you need to return a string instead of an integer.

#include "../header.h"

void largetstNumber(vi &arr)
{
    vs num(arr.size());
    for (int i = 0; i < num.size(); i++)
        num[i] = to_string(arr[i]);
    sort(all(num), [=](string a, string b)
         { return a + b < b + a; });

    reverse(all(num));
    for (auto val : num)
        cout << val << " ";
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr(n);
        rarr(arr, 0, n);

        cout << "\n============================================\n";
        largetstNumber(arr);
        cout << "\n============================================\n";
    }
    return 0;
}

/*
5
34 5 3 30 9
*/