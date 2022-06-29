// 1. You are given a string str. The string str will contains numbers only, where each number stands for a key pressed on a mobile phone.
// 2. The following list is the key to characters map :
//     0 -> .;
//     1 -> abc
//     2 -> def
//     3 -> ghi
//     4 -> jkl
//     5 -> mno
//     6 -> pqrs
//     7 -> tu
//     8 -> vwx
//     9 -> yz
// 3. Complete the body of getKPC function - without changing signature - to get the list of all words that could be produced by the keys in str.
// Use sample input and output to take idea about output.

#include "../header.h"

vector<string> kpc(string *keypad, string str)
{
    vector<string> temp, res;
    if (str.length() == 0)
    {
        temp.pb("");
        return temp;
    }
    int n = str[0] - '0';
    cout << n << endl;
    temp = kpc(keypad, str.substr(1));
    for (auto item : temp)
        for (auto ch : keypad[n])
            res.pb(ch + item);
    return res;
}

int main()
{
    cout << "hello!" << endl;

    vector<string> seq;
    string keypad[] = {".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
    seq = kpc(keypad, "5670");
    parr(seq, seq.size());

    return 0;
}

// 78