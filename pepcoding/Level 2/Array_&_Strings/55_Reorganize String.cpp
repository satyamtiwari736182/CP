// https://leetcode.com/problems/reorganize-string/

#include "../header.h"

typedef pair<int, char> pic;

string reOrganiseString(string str)
{
    int cnt[26] = {0};
    for (char ch : str)
        cnt[ch - 'a']++;

    priority_queue<pic> pque;

    for (int i = 0; i < 26; i++)
        if (cnt[i] > 0)
            pque.push({cnt[i], (char)(i + 'a')});

    string res = "";
    pic block = pque.top();
    pque.pop();
    res += block.se;
    block.fs--;
    while (!pque.empty())
    {
        pic temp = pque.top();
        pque.pop();
        res += temp.se;
        temp.fs--;
        if (block.fs > 0)
            pque.push(block);
        block = temp;
    }

    return res;
}

void solve()
{
    string str;
    cin >> str;
    cout << "--------------------" << endl;
    cout << reOrganiseString(str);
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
pepcoding
*/
