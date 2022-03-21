#include "../header.h"
int sol(vi arr)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int val = arr[i];
        for (int k = i + 1; k < arr.size(); k++)
        {
            val = val ^ arr[k];
            if (val == 0)
                count += (k - i);
        }
    }
    return count;
}

int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;
    vi arr;
    rvarr(arr, 0, n);

    cout << "\n========================================\n";
    cout << sol(arr);
    cout << "\n========================================\n";
    return 0;
}
// 10
// 1 3 2 5 7 2 7 5 6 4


