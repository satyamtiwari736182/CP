// 1. You are given a string containing only 0's and 1's.
// 2. You have to find the length of substring which is having maximum difference of number of 0s and number of 1s i.e (Number of 0's - Number of 1's).
// 3. If there are all 1's present in the given string, then print '-1'.

#include "../header.h"

int solution(string str)
{
    int ans = 0, csum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int val = 0;

        if (str[i] == '0')
            val++;
        else if (str[i] == '1')
            val--;

        if (csum > 0)
            csum += val;
        else
            csum = val;

        ans = max(ans, csum);
    }
    return ans;
}

int main()
{
    cout << "\nHello world!\n";
    string str;
    cin >> str;
    cout << "\n==========\n";
    //------------------------------------------------------
    cout << solution(str) << endl;
    return 0;
}

/*
11000010001
*/

