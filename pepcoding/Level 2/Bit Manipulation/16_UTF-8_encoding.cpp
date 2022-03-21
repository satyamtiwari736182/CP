#include "../header.h"

bool sol(vi arr)
{
    int rbytes = 0;
    for (int val : arr)
    {
        if (rbytes == 0)
        {
            if ((val >> 7) == 0b0)
                rbytes = 0;
            else if ((val >> 5) == 0b110)
                rbytes = 1;
            else if ((val >> 4) == 0b1110)
                rbytes = 2;
            else if ((val >> 3) == 0b11110)
                rbytes = 3;
        }
        else
        {
            if ((val >> 6) == 0b10)
                rbytes--;
            else
                return false;
        }
    }
    if (rbytes == 0)
        return true;
    else
        return false;
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
