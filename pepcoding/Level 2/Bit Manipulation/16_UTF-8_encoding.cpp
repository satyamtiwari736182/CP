// 1. You are given an array of integers.
// 2. You are required to test whether the array represents a valid sequence of UTF-8 characters or 
//      not.
// 3. A character in UTF-8 can be from 1 to 4 bytes long and follows some rules - 
//        (i)  For 1-byte long character, first bit will be 0 and rest represents its unicode code.
//        (ii) For n-bytes long character, first n-bits will be 1's, the n+1th bit is 0, followed by n-1 bytes 
//              with most significant 2 bits being 10.

// Note -> Only the least significant 8 bits of each element in array is used for data.
// Note -> Check out the question video for details.



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


// 3
// 197
// 130
// 1