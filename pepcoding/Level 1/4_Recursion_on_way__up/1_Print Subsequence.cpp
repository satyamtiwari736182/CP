// 1. You are given a string str.
// 2. Complete the body of printSS function - without changing signature - to calculate and print all subsequences of str.
// Use sample input and output to take idea about subsequences.

#include "../header.h"

void printseq(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << " ";
        return;
    }
    printseq(str.substr(1), ans + str[0]);
    printseq(str.substr(1), ans + "");
}

int main()
{
    cout << "hello!" << endl;
    printseq("abc", "");
    return 0;
}

// yvTA