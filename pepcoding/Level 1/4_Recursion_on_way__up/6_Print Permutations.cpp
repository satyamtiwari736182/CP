
// 1. You are given a string str.
// 2. Complete the body of printPermutations function - without changing signature - to calculate and print all permutations of str.
// Use sample input and output to take idea about permutations.

#include "../header.h"

void permute(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << " ";
        return;
    }
    for (int i = 0; i < str.length(); i++)
        permute(str.substr(0, i) + str.substr(i + 1), ans + str[i]);
}

int main()
{
    cout << "hello!" << endl;
    permute("abcd", "");

    return 0;
}

// abc