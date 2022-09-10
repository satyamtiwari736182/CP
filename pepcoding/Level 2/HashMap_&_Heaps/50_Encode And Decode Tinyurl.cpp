// https://leetcode.com/problems/encode-and-decode-tinyurl/

#include "../header.h"
unordered_map<string, string> hashmap;

string encode(string longUrl)
{
    string str = "";
    str += (char)rand() % 127;
    while (hashmap.count(str))
        str += (char)rand() % 127;

    hashmap[str] = longUrl;
    return str;
}

string decode(string shortUrl)
{
    return hashmap[shortUrl];
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    test(t)
    {

        cout << "\n============================================\n";
        cout << encode("www.pepcoding.com") << endl;
        cout << decode(")") << endl;
        cout << "\n============================================\n";
    }

    return 0;
}