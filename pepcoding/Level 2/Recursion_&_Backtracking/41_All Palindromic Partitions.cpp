// 1. You are given a string of length n.
// 2. You have to partition the given string in such a way that every partition is a palindrome.

// Note -> Check out the question video and write the recursive code as it is intended without
//                changing signature. The judge can't force you but intends you to teach a concept.

#include "../header.h"

bool isPalindrome(string str)
{
    int left = 0, right = str.length() - 1;
    while (left < right)
    {
        if (str[left] != str[right])
            return false;
        left++, right--;
    }
    return true;
}

void solution(string str, string asf)
{
    if (str.length() <= 0)
    {
        cout << asf << endl;
        return;
    }
    for (int i = 0; i < str.length(); i++)
    {
        string prefix = Substr(str, 0, i + 1);
        string rem_str = Substr(str, i + 1, str.length());
        if (isPalindrome(prefix))
            solution(rem_str, asf + "(" + prefix + ") ");
    }
}
void solve()
{
    string str;
    cin >> str;
    solution(str, "");
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

// pep

// aaabb