#include "../header.h"

int solution(vi &arr)
{
    map<int, int> hashmap;
    int cnt = 0;
    int i = -1;
    int n = arr.size();
    int sum = 0;
    hashmap.insert({sum, 1});

    while (i < n)
    {
        i++;
        sum += arr[i];
        if (hashmap.find(sum) != hashmap.end())
            cnt += hashmap[sum];
        hashmap[sum]++;
    }

    return cnt;
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

        cout << "\n============================================\n";

        cout << solution(arr);

        cout << "\n============================================\n";
    }
    return 0;
}

// 2

// 8
// 15 -2 2 -8 1 7 10 23

// 12
// 2 8 -3 -5 2 -4 6 1 2 1 -3 4
