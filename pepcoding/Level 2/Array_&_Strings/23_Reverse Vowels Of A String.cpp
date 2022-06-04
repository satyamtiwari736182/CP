
// 1. Given a string 's'.
// 2. Reverse only all the vowels in the string and return it.
// 3. The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.

#include "../header.h"

bool isVowel(char ch)
{
    char vowel[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (char vl : vowel)
        if (ch == vl)
            return true;
    return false;
}

void solve()
{
    string str;
    cin >> str;
    int i = 0, j = str.length() - 1;

    while (i < j)
    {
        while (j > i && !isVowel(str[j]))
            j--;
        while (i < j && !isVowel(str[i]))
            i++;

        swap(str[i], str[j]);
        i++, j--;
    }

    cout << str << endl;
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

PepCoding

*/
