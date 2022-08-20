// 1. You are given a string and a pattern. 
// 2. You've to check if the string is of the same structure as pattern without using any regular 
//      expressions.

// Note -> Check out the question video and write the recursive code as it is intended without 
//                changing signature. The judge can't force you but intends you to teach a concept.

#include "../header.h"

void solution(string str, string patt, unordered_map<char, string> &hashmap, string op)
{
    if (patt.length() == 0)
    {
        if (str.length() == 0)
        {
            unordered_set<char> alreadyPrinted;
            for (char ch : op)
                if (alreadyPrinted.count(ch) == 0)
                {
                    cout << ch << " -> " << hashmap[ch] << endl;
                    alreadyPrinted.insert(ch);
                }
        }
        return;
    }

    char ch = patt[0];
    string rem_patt = patt.substr(1);

    if (hashmap.count(ch))
    {
        string previousMapping = hashmap[ch];
        if (str.length() >= previousMapping.length())
        {
            string left = Substr(str, 0, previousMapping.length());
            string right = Substr(str, previousMapping.length(), str.length());
            if (previousMapping == left)
                solution(right, rem_patt, hashmap, op);
        }
    }
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            string left = Substr(str, 0, i + 1);
            string right = str.substr(i + 1);
            hashmap[ch] = left;
            solution(right, rem_patt, hashmap, op);
            hashmap.erase(ch);
        }
    }
}

void solve()
{
    string str, patt;
    cin >> str >> patt;
    unordered_map<char, string> hashmap;
    solution(str, patt, hashmap, patt);
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
graphtreesgraph
pep
*/