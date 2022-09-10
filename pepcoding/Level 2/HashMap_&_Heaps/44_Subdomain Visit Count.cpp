// 1. A website domain like "www.pepcoding.com" consists of various subdomains like
//    "com" at the topmost level, "pepcoding.com" at the next level, and "www.pepcoding.com" at the lowest level.
// 2. When you visit a domain like "www.pepcoding.com", you will also visit its parent domains "pepcoding.com" and "com".
// 3. You are given N number of strings where every string contains a number and a domain separated by a space, where the number represents the visit count of the domain.
// 4. You have to find the number of visits for each sub-domain.

#include "../header.h"
#include <cstring>

vs solve(vs &domains)
{
    unordered_map<string, int> hashmap;
    for (string domain : domains)
    {
        int visitCount = 0;
        vs temp, words;
        temp = split(domain, " ");

        convert(temp[0], visitCount);

        string subDomain = "";
        words = split(temp[1], "\\.");
        for (int idx = words.size() - 1; idx >= 0; idx--)
        {
            if (idx == words.size() - 1)
                subDomain += words[idx];
            else
                subDomain = "." + subDomain, subDomain = words[idx] + subDomain;

            hashmap[subDomain] += visitCount;
        }
    }

    vs res;
    for (auto pr : hashmap)
        res.pb(to_string(pr.se) + " " + pr.fs + "\n");
    sort(all(res));
    return res;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    test(t)
    {
        int n;
        cin >> n;
        vs str(n);
        for (int i = 0; i < n; i++)
            fflush(stdin), getline(cin, str[i]);

        cout << "\n============================================\n";
        vs res = solve(str);
        for (int i = 0; i < res.size(); i++)
            cout << res[i];
        cout << "\n============================================\n";
    }

    return 0;
}

// 1
// 9999 www.pepcoding.com