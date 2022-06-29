// 1. You are given a string str of digits. (will never start with a 0)
// 2. You are required to encode the str as per following rules
//     1 -> a
//     2 -> b
//     3 -> c
//     ..
//     25 -> y
//     26 -> z
// 3. Complete the body of printEncodings function - without changing signature - to calculate and print all encodings of str.
// Use the input-output below to get more understanding on what is required
// 123 -> abc, aw, lc
// 993 -> iic
// 013 -> Invalid input. A string starting with 0 will not be passed.
// 103 -> jc
// 303 -> No output possible. But such a string maybe passed. In this case print nothing.

#include "../header.h"

void printencoding(string ques, string ans)
{
    if (ques.length() == 0)
    {
        cout << ans << " ";
        return;
    }
    else if (ques.length() == 1)
    {
        int val = stoi(ques.substr(0, 1));
        if (val == 0)
            return;
        char ch = char(val + 'a' - 1);
        ans = ans + ch;
        cout << ans << " ";
        return;
    }
    else
    {
        int ch1 = stoi(ques.substr(0, 1));
        int ch2 = stoi(ques.substr(0, 2));
        if (ch1 == 0 || ch2 > 26)
            return;
        ch1 = ch1;
        char ch = char(ch1 + 'a' - 1);
        printencoding(ques.substr(1), ans + ch);
        ch = char(ch2 + 'a' - 1);
        printencoding(ques.substr(2), ans + ch);
    }
}

int main()
{
    cout << "hello!" << endl;
    printencoding("123", "");

    return 0;
}

// 655196