#include "../header.h"
vi anagram_mapping(vi &arrA, vi &arrB)
{
    vi mapping(arrA.size());
    map<int, vi> hashmap;
    for (int i = 0; i < arrB.size(); i++)
        hashmap[arrB[i]].pb(i);

    for (int i = 0; i < arrA.size(); i++)
    {
        vi &indexes = hashmap[arrA[i]];
        mapping[i] = indexes[0];
        indexes.erase(indexes.begin());
    }

    return mapping;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t, n;
    cin >> t;
    test(t)
    {
        cin >> n;
        vi arrA, arrB;
        rvarr(arrA, 0, n);
        rvarr(arrB, 0, n);
        cout << "\n============================================\n";
        vi mapping = anagram_mapping(arrA, arrB);
        for (int val : mapping)
            cout << val << " ";
        cout << "\n============================================\n";
    }

    return 0;
}

// 1
// 6
// 1 2 3 4 5 2
// 4 3 2 1 5 2
