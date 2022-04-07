#include "../header.h"

vi solve(vi &arr)
{
    if (arr.size() == 0)
        return {-1};

    int startidx = 0, endidx = 0, maxfreq_ele = arr[0], length = 1;
    map<int, int> hashmap_freq, hashmap_startIdx;

    for (int i = 0; i < arr.size(); i++)
    {
        hashmap_freq[arr[i]]++;
        if (hashmap_startIdx.count(arr[i]) == 0)
            hashmap_startIdx[arr[i]] = i;

        if (hashmap_freq[maxfreq_ele] < hashmap_freq[arr[i]] || arr[i] == maxfreq_ele)
        {
            maxfreq_ele = arr[i];
            startidx = hashmap_startIdx[arr[i]];
            endidx = i;
            length = endidx - startidx + 1;
        }

        else if (hashmap_freq[maxfreq_ele] == hashmap_freq[arr[i]])
        {
            int newlength = i - hashmap_startIdx[arr[i]] + 1;
            if (newlength < length)
            {
                maxfreq_ele = arr[i];
                startidx = hashmap_startIdx[arr[i]];
                endidx = i;
                length = endidx - startidx + 1;
            }
        }
    }

    return {maxfreq_ele, startidx, endidx};
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
        vi ans = solve(arr);
        for (int val : ans)
            cout << val << " ";

        cout << "\n============================================\n";
    }

    return 0;
}

// 3

// 8
// 4 1 1 2 2 1 3 3

// 12
// 8 8 4 2 0 2 1 4 0 16 8 4

// 20
// 1 3 2 4 2 3 4 2 5 6 5 5 7 102 7 45 65 89 7 30
