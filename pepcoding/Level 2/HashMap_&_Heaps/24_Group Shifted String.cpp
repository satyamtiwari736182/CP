
// 1. You are given an array of strings.
// 2. You have to group the given strings in such a way that all strings in a group are shifted versions of each other. 
// 3. Two strings s1 and s2 are shifted if -
//    -> Length of both the strings is the same.
//    -> The difference between ASCII values of every character of s1 and s2 is constant.

// Note -> Every string consists of lower-case English letters only.

#include "../header.h"

void group_shifted_str(vs &arr)
{
    map<string, vs> hashmap;
    for (string str : arr)
    {
        string hashDiff = "";
        for (int i = 0; i < str.length() - 1; i++)
        {
            int diff = (str[i] - str[i + 1] + 26) % 26;
            hashDiff = hashDiff + to_string(diff) + "#";
        }
        hashmap[hashDiff].pb(str);
    }

    vector<vs> lst(hashmap.size());
    for (auto pr : hashmap)
        lst.pb(pr.se);
    sort(all(lst));

    for (auto lists : lst)
    {
        for (auto str2 : lists)
            cout << str2 << " ";
        cout << endl;
    }
}

int main()
{
    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    test(t)
    {
        int n;
        cin >> n;
        vs arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << "\n============================================\n";
        group_shifted_str(arr);

        cout << "\n============================================\n";
    }

    return 0;
}

// 1
// 9
// acd dfg wyz yab mop bdfh a x moqs
