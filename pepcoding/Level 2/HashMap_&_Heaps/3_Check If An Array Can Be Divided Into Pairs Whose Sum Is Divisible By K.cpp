#include "../header.h"

bool checkPair(vi &arr, int k)
{
    map<int, int> hashmap;
    for (int val : arr)
    {
        int rem = val % k;
        hashmap[rem]++;
    }

    for (int val : arr)
    {
        int rem = val % k;
        if (rem == 0)
        {
            int fq = hashmap[rem];
            if (fq % 2 == 1)
                return false;
        }
        else if (2 * rem == k)
        {
            int fq = hashmap[rem];
            if (fq % 2 == 1)
                return false;
        }
        else
        {
            int fq = hashmap[rem];
            int ofq = hashmap[k - rem];
            if (fq != ofq)
                return false;
        }
    }
    return true;
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
        vi arr;
        rvarr(arr, 0, n);
        int k;
        cin >> k;

        cout << "\n============================================\n";
        cout << checkPair(arr, k);
        cout << "\n============================================\n";
    }
    return 0;
}
// 3           

// 4
// 9 7 5 3
// 6

// 9
// 56 25 72 44 80 36 96 71 55
// 8

// 10
// 22 12 45 55 65 78 88 75 62 80
// 11