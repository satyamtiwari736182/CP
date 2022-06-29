// 1. You are given a string str.
// 2. Complete the body of getSS function - without changing signature - to calculate all subsequences of str.
// Use sample input and output to take idea about subsequences.

#include "../header.h"

vector<string> getseq(string str, vector<string> res)
{
    vector<string> temp;
    if (str.length() == 0)
    {
        temp.pb("");
        return temp;
    }

    temp = getseq(str.substr(1), res);

    for (auto item : temp)
        res.pb("" + item);
    for (auto item : temp)
        res.pb(str[0] + item);

    return res;
}

int main()
{
    cout << "hello!" << endl;

    vector<string> seqs;
    seqs = getseq("abc", seqs);
    parr(seqs, seqs.size());

    return 0;
}

// abc