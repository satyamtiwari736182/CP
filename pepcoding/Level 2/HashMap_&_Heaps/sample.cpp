#include "../header.h"

// typedef vector<string> vs;
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

    return hashmap_B.size();
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
        group_Anagrams(arr);

        cout << "\n============================================\n";
    }

    return 0;
}

// 1
// 5
// pepcoding codingpep pepper rapper repepp

/*
1
5
cat listen silent kitten salient
*/
