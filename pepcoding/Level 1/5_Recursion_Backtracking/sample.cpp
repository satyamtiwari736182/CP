#include "../header.h"

vector<string> allSubseq(string str)
{
    vector<string> samm;
    samm.pb("");
    if (str.length() == 0)
        return samm;
    char ch = str[0];

    auto rres = allSubseq(str.substr(1));

    vector<string> sam;
    for (auto i : rres)
        sam.pb(ch + i);
    for (auto i : rres)
        sam.pb("" + i);

    return sam;
}

int main()
{
    cout << "hello!" << endl;
    int n, arr[100];
    cin >> n;
    rarr(arr, 0, n);
    auto res = allSubseq("abc");
    parr(res, res.size());
    return 0;
}

/*
6
3 2 5 9 2 4
*/

/*
6
6
0 1 4 2 8 2
4 3 6 5 0 4
1 2 4 1 4 6
2 0 7 3 2 2
3 1 5 9 2 4
2 7 0 8 5 1
*/