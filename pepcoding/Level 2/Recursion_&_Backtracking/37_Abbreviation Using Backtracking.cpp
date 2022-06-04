// 1. You are given a word.
// 2. You have to generate all abbrevations of that word.

// Use recursion as suggested in question video



#include "../header.h"

void printAbbreb(string str, string asf, int count, int pos)
{
    if (pos == str.length())
    {
        if (count == 0)
            cout << asf << " ";
        else
            cout << asf << count << " ";
        return;
    }
    if (count > 0)
        printAbbreb(str, asf + to_string(count) + str[pos], 0, pos + 1);
    else
        printAbbreb(str, asf + str[pos], 0, pos + 1);
    printAbbreb(str, asf, count + 1, pos + 1);
}

int main()
{
    cout << "\nHello world!" << endl;
    string str;
    cin >> str;
    printAbbreb(str, "", 0, 0);

    return 0;
}


// pep