#include "../header.h"

// typedef vector<string> vs;

// typedef vector<int> vi;
int sample(vi &arr)
{
    // int m = 1e9 + 7;
    int cnt = 0;
    sort(arr.begin(), arr.end(), [=](int a, int b)
         { return b < a; });
    if (arr[0] > 0)
        cnt++;
    for (int i = 1; i < arr.size(); i++)
    {
        arr[i] = (arr[i] % mod + arr[i - 1] % mod + mod) % mod;
        if (arr[i] > 0)
            cnt++;
    }
    return cnt;
}
// -3 0 2 1
// 2 1 0 -3
// 2 3 3 0

int fun(vs &word)
{
    unordered_map<string, int> hashmap;
    for (string str : word)
    {
        set<char> hashset;
        for (char ch : str)
            hashset.insert(ch);
        string str2 = "";
        for (char ch : hashset)
            str2 += ch;
        hashmap[str2]++;
    }
    int cnt = 0;
    for (auto pr : hashmap)
        if (pr.second >= 2)
            cnt++;

    return cnt;
}

int group_Anagrams(vs &arr)
{
    map<map<char, int>, vs> hashmap_B;
    for (string str : arr)
    {
        map<char, int> hashmap;
        for (char ch : str)
            hashmap[ch]++;
        hashmap_B[hashmap].pb(str);
    }

    int cnt = 0;
    for (auto pr : hashmap_B)
        if (pr.second.size() > 0)
        {

            cout << pr.second.size() << " ";
            cnt++;
        }
    cout << endl;
    return cnt;
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
        vs arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << "\n============================================\n";
        // cout << group_Anagrams(arr);
        cout << fun(arr);

        cout << "\n============================================\n";
    }

    return 0;
}

// 1
// 5
// pepcoding codingpep pepper rapper repepp

/*
1
3
xyz of foo

4
aba abaca baab cba
*/
