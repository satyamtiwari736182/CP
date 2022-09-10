// https://leetcode.com/problems/random-pick-with-blacklist/

#include "../header.h"
#include <time.h>
unordered_map<int, int> hashmap; // blacklisted=>non-blacklisted
int up_nonBlkList_cnt = 0;
void solution(int n, vi &blackList)
{
    up_nonBlkList_cnt = n - blackList.size(); // assumed to hold
    unordered_set<int> blkListSet(all(blackList));
    // n--;
    for (int i = 0; i < blackList.size(); i++)
        if (blackList[i] < up_nonBlkList_cnt)
        {
            while (blkListSet.count(n) == true)
                n--;
            hashmap[blackList[i]] = n;
            n--;
        }
    // for (pi pr : hashmap)
    //     cout << pr.fs << " -> " << pr.se << endl;
}

int pick()
{
    int randIdx = rand() % up_nonBlkList_cnt;
    if (hashmap.count(randIdx) == true)
        return hashmap[randIdx];
    return randIdx;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    test(t)
    {
        int n, rng;
        cin >> rng >> n;
        vi blkList(n);
        rarr(blkList, 0, n);
        solution(rng, blkList);
        for (int i = 0; i < 20; i++)
        {
            int idx = pick();
            cout << idx << " ";
            // srand(idx + time(0) * 7);
        }
        cout << "\n============================================\n";
        cout << "\n============================================\n";
    }

    return 0;
}

/*
20
5
3 7 9 16 19
*/